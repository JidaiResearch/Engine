Waypoints = function() {
	this.waypoints = []
	this.edges = []
	this.entities = []
	this.edgeents = []
}

Waypoints.prototype.add = function(origin) {
	this.waypoints.push( origin )

	
	var model = spawnentity()
	model.origin = origin.sub( Vec3(0,0,25) )
	model.model = "models/items/forcegem.md3"
	this.entities.push( model )

	return this.waypoints.length - 1 // return the "id"
}

Waypoints.prototype.saveToFile = function(filename) {
	var content = "var waypoints = new Waypoints();\n";
	for (var i=0; i<this.waypoints.length; i++) {
		var wp = this.waypoints[i]
		content += "waypoints.add( " + wp.toString() + " );\n"
	}
	content += "waypoints;" // last statement of eval(...) is returned
	file_put_contents(filename, content)
}


Waypoints.prototype.reset = function() {
	for (var i in this.entities) {
		this.entities[i].free()
	}
	for (var i=0; i<this.edgeents.length; i++)
		this.edgeents[i].free()
	this.waypoints = []
	this.edges = []
	this.entities = []
	this.edgeents = []
	//for (var i=0; i<this.waypoints.length; i++) {
	//	var wp = this.waypoints[i]
	//}
}

Waypoints.prototype.spawnEdgeEnts = function() {
	for (var i=0; i<this.edgeents.length; i++)
		this.edgeents[i].free()
	this.edgeents = []

	for (var i=0; i<this.edges.length; i++) {
		var edge_from = this.edges[i][0]
		var edge_to   = this.edges[i][1]

		var wp_from = this.waypoints[edge_from]
		var wp_to   = this.waypoints[edge_to  ]

		var delta = wp_to.sub(wp_from);
		var angles = vecToAngles(delta)

		var edgeent = spawnentity()
		edgeent.origin = wp_from
		edgeent.angles = angles.add( Vec3(0,90,90) )
		edgeent.model = "models/items/battery.md3"
		this.edgeents[i] = edgeent

		console.log(edge_from, edge_to, angles)
	}
}

Waypoints.LoadFromFile = function(filename) {
	var content = file_get_contents(filename)
	return eval(content);
}


load_waypoints = function() {
	if (typeof waypoints != "undefined") {
		waypoints.__proto__ = Waypoints.prototype
		waypoints.reset()
		
	}
	waypoints = Waypoints.LoadFromFile("waypoints.txt")
	
	waypoints.edges.push( [0,1] )
	waypoints.edges.push( [1,0] )
	
	waypoints.edges.push( [1,2] )
	waypoints.edges.push( [2,1] )
	
	waypoints.edges.push( [2,3] )
	waypoints.edges.push( [3,2] )
	
	waypoints.spawnEdgeEnts()
}

/*
	waypoints.add( player.origin )
	//waypoints.reset()
	waypoints.__proto__ = Waypoints.prototype
	v = new Float32Array(3)
	v.toJSON = function() {
	return "bla"
	}


	v = Vec3(11,22,33)
	v.toString()
	JSON.stringify(v)
	JSON.stringify( Vec3(0,1,2) )

	waypoints = new Waypoints()
	waypoints.add( player.origin )
	waypoints.saveToFile("waypoints.txt")
	waypoints.connect(0, 1)

	Waypoint = function(origin) {
		this.origin = origin	
		this.neighbors = [];
	}

	Waypoint.prototype.distance = function(to) {
		var dx = to.origin.x - this.origin.x
		var dy = to.origin.y - this.origin.y
		var dz = to.origin.z - this.origin.z
		var dist =  Math.sqrt(dx*dx + dy*dy + dz*dz)
		//console.log(this.neighbors[to])
		console.log("distance from '" + this.name + "' to '" + to.name + "' is: " + dist);
		return dist
	}

	Waypoint.prototype.connectTo = function(other) {
		this.neighbors.push( other )
	}

	a = new Waypoint(player.origin)
	b = new Waypoint(player.origin)
	c = new Waypoint(player.origin)
	d = new Waypoint(player.origin)

	a.connectTo(b)
	b.connectTo(c)
	c.connectTo(d)

	a.name = "a"
	b.name = "b"
	c.name = "c"
	d.name = "d"

	//d.neighbors
		
		path = new Astar().findPath(a, d)
		var tmp = []
		for (i=0; i<path.length; i++) {
			//tmp.push()
			console.log(path[i].name)
		}
*/
