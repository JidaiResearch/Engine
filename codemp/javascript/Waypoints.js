Waypoints = function() {
	this.waypoints = []
	this.edges = []
	this.entities = []
}

Waypoints.prototype.add = function(origin) {
	this.waypoints.push( origin )
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


Waypoints.prototype.show = function() {

	for (var i in this.entities) {
		this.entities[i].free()
	}
	this.entities = []
	for (var i=0; i<this.waypoints.length; i++) {
		var wp = this.waypoints[i]

		var model = spawnentity()
		model.origin = wp.sub( Vec3(0,0,25) )
		model.model = "models/items/forcegem.md3"


		this.entities.push( model )
	}
}

Waypoints.LoadFromFile = function(filename) {
	var content = file_get_contents(filename)
	return eval(content);
}

waypoints = Waypoints.LoadFromFile("waypoints.txt")
waypoints.show()
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