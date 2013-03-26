println("-- test.js -- ");

function setup () {
	
	println("setup");	
	
}

function update () {
	
	var time = of.GetElapsedTimeMillis();
	
	var pct = 0.5 + Math.cos(time / 5000) * 0.5;
	
	println(pct);
	
	for ( var i=0; i<numSharpy; i++) {
	
	pct = 0.5 + Math.cos(time * i / 10000) * 0.5;
	
	setOrientation(i, -90 + (pct * 180), 0, 0);	
	setBrightness(i, pct);
	
	}
	
}