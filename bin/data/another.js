println("-- Simple Cosinus example.js -- ");

function setup (s) {
		
	var time = of.GetElapsedTimeMillis();
	
	for ( var i=0; i<2; i++) {
		
		for (var j=0; j<16; j++) {
		
			var index = i * 16 + j;
			setOrientation(s, index,  0, 0, 0);	
			setGobo(s, index, 1.0);
		}
	}
	
}

function update (s) {

	
	var time = of.GetElapsedTimeMillis();
			
	for ( var i=0; i<2; i++) {
		
		for (var j=0; j<16; j++) {
			
			var index = i * 16 + j;
			var pct = Math.cos(time *  j / 3000) * 10;
			
			var pan = (i % 2 == 0) ? pct:  pct;
			
			setOrientation(s, index,  -pct, -45, 0);	
			setGobo(s, index, 1.0);
			setBrightness(s, index, 1);
		}
		
		
	}
	
	
	
}