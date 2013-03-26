println("-- test.js -- ");

function setup () {
		
	var time = of.GetElapsedTimeMillis();
	
}



function update () {
	
	var time = of.GetElapsedTimeMillis();
	
	var pct = 0.5 + Math.cos(time / 500) * 0.5;
	
	//println(pct);
	
	for ( var i=0; i<2; i++) {
		
		for (var j=0; j<16; j++) {
			
			var index = i * 16 + j;
			var jPct = j / 16 * pct;
			
			var pan = (i % 2 == 0) ? -90 + (jPct * 180):  90 -(jPct * 180);
			
			setOrientation(index, pan * pct, 0, 0);	
			setGobo(index, 1.0 - pct);
			
			
			
		}
		
	}	
	
}