/*
pos = entities[0].traceEyeEntity(1024).position
ent = spawnentity()
ent.setOrigin(pos)
ent.setModel("kungmodels/heart.kung1")
*/
function spawnentity() {
	return entities[g_spawn()];
}

function Entity(id) {
	this.id = id;
	this.threads = [];
	this.thread = function(func) {
		var self = this;
		return function() {
			var t = new Duktape.Thread(function(args) {
				func.bind(self)(args[0], args[1], args[2], args[3], args[4], args[5], args[6], args[7], args[8], args[9]);
				//func.apply(self, arguments) // waiting for: https://github.com/svaarala/duktape/issues/1420
			});
			t.nextrun = level.time;
			t.parameters = arguments;
			t.events = [];
			t.entity = self;
			t.userkill = false;
			t.eval = function(code) { return Duktape.Thread.resume(t, code); }
			t.doFirstCall = true;
			self.threads.push(t)
			//level.currentthread = t;
			//Duktape.Thread.resume(t, arguments);
			
		}
	}
	

	this.runframe = function() {
		// iterate backwards over it, so we can delete finished threads instantly via ID
		for (var i=this.threads.length-1; i>=0; i--) {
			var thread = this.threads[i];

			var state = Duktape.info(thread);
			//printf("entid=% threadid=% state=%,%\n", this.id, i, state[0], state[1]);

			if (thread.nextrun > level.time) {
				//printf("entid=% threadid=%> No run yet: nextrun in %\n", this.id, i, thread.nextrun - level.time)
				continue;
			}

			// user called killthread()
			if (thread.userkill) {
				//printf("DELETE THREAD %d\n", this.id);
				this.threads.splice(i, 1); // delete thread from array
				continue;
			}		
			
			try {
				level.currentthread = thread;
				var arg = undefined;
				if (thread.doFirstCall) {
					arg = thread.parameters;
					thread.doFirstCall = false;
				}
				var whatnow = undefined;
				try {
					whatnow = Duktape.Thread.resume(thread, arg);
				} catch (e) {
					printf("error runframe: %\n", e);
					
				}

				var state = Duktape.info(thread);
				//printf("AFTER RESUME: entid=% threadid=% state=%,%\n", this.id, i, state[0], state[1]);

				switch (whatnow[0]) {
					case "wait": thread.nextrun += whatnow[1];	break;
				}
				//printf("whatnow: %\n", whatnow);
			} catch (e) {
				this.threads.splice(i, 1); // delete thread from array
				//printf("Entity::runframe> Finished Thread id=% entityid=% level.time=%\n", i, this.id, level.time);

			}
		}
	}

	
	this.disconnect = function() {
		printf("js> entityid=%d disconnected\n", this.id);

		for (var i=0; i<this.threads.length; i++) {
			var thread = this.threads[i];
			var callbacks = thread.events["disconnect"];
			
			// yea honestly, some threads do not define a disconnect event :^)
			if (typeof callbacks == "undefined") {
				continue;
			}
			
			// iterate over all callbacks and call them bounded to this entity
			for (var j=0; j<callbacks.length; j++)
			{
				callbacks[j].bind(this)();
			}
			
			// when we have called all callbacks, remove them
			thread.events["disconnect"] = [];
			
		}
	}
	
	this.useButtonPressed    = function()                      { return entity_usebuttonpressed   (this.id);                                           }
	this.sprintButtonPressed = function()                      { return entity_sprintbuttonpressed(this.id);                                           }
	this.attackButtonPressed = function()                      { return entity_attackbuttonpressed(this.id);                                           }
	this.getEye              = function()                      { return entity_get_eye            (this.id);                                           }
	this.getOrigin           = function()                      { return entity_get_origin         (this.id);                                           }
	this.setOrigin           = function(origin)                { return entity_set_origin         (this.id, origin[0], origin[1], origin[2]);          }
	this.addEvent            = function(normal)                { return entity_add_event          (this.id, normal[0], normal[1], normal[2]);          }
	this.getAngles           = function()                      { return entity_get_angles         (this.id);                                           }
	this.getWeapon           = function()                      { return entity_get_weapon         (this.id);                                           }
	this.getWeaponState      = function()                      { return entity_get_weaponstate    (this.id);                                           }
	this.getWeaponTime       = function()                      { return entity_get_weapontime     (this.id);                                           }
	this.setAngles           = function(angles)                { return entity_set_angles         (this.id, angles[0], angles[1], angles[2]);          }	
	this.getForward          = function()                      { return entity_get_forward        (this.id);                                           }
	this.getClassname        = function()                      { return entity_get_classname      (this.id);                                           }
	this.moveTo              = function(pos, durationSeconds)  { return entity_moveto             (this.id, pos[0], pos[1], pos[2], durationSeconds);  }
	this.solid               = function()                      { return entity_solid              (this.id);                                           }
	this.suicide             = function()                      { return entity_suicide            (this.id);                                           }
	this.die                 = function(self, inflictor, attacker, damage, mod)                   { return entity_die                (self.id, inflictor.id, attacker.id, damage, mod);                                           }
	this.free                = function()                      { return entity_delete             (this.id);                                           } // same, whatever u prefer
	this.unlink              = function()                      { return entity_delete             (this.id);                                           } // same, whatever u prefer
	this.notSolid            = function()                      { return entity_notsolid           (this.id);                                           }
	this.setModel            = function(modelname)             { return entity_set_model          (this.id, modelname);                                }
	
	this.printf = function() {
		var msg = sprintf.apply(undefined, arguments);
		sendservercommand(this.id, "print \"" + msg + "\"");
	}
}

Entity.prototype.traceEyeEntity = function(distance, ignoredEntity) {
	var eye = this.getEye();
	var forward = this.getForward();
	var endpos = vec3_new();
	vec3_a_is_b_plus_c_times_d(endpos, eye, forward, distance)
	//printf("endpos=%, eye=%, forward=%, distance=%\n", endpos, eye, forward, distance);
	var tmp = bullettrace(eye, endpos, "useless", ignoredEntity);
	return tmp;
}

Entity.prototype.setMoney = function(money) {
	this.money = money;	
	this.hudMoney.setText("Money: " + this.money);
}

function vec4(a,b,c,d) {
	var ret = new Float32Array(4);
	ret[0] = a;
	ret[1] = b;
	ret[2] = c;
	ret[3] = d;
	return ret;
}

function JS_getPlayersInRange(position, maxDistance) {
	var ret = getPlayersInRange(position[0], position[1], position[2], maxDistance);
	ents = [];
	for (var i=0; i<ret.length; i++) {
		ents.push( entities[ret[i]] );
	}
	return ents;
}

Entity.prototype.getPlayersInRange = function(maxDistance) {
	return JS_getPlayersInRange(this.getOrigin(), maxDistance);	
}



if (typeof entities == "undefined") {
	entities = Array(1024);
	for (var i=0; i<1024; i++)
		entities[i] = new Entity(i);
}
