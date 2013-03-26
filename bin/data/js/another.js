println("-- another.js -- ");

function setup () {
		
	var time = of.GetElapsedTimeMillis();
	
	for ( var i=0; i<2; i++) {
		
		for (var j=0; j<16; j++) {
			
			
			var index = i * 16 + j;
			//setOrientation(index,  0, 0, 0);	
			setGobo(index, 1.0);
			
		}
		
		
	}
	
}



function update () {

	println("ahou");
	
	var time = of.GetElapsedTimeMillis();
	
	var Apct = 0.5 + Math.cos(time / 5000) * 0.5;
		
	for ( var i=0; i<2; i++) {
		
		for (var j=0; j<16; j++) {
			
			var index = i * 16 + j;
			pct = Math.cos(time *  j / 3000) * 10;
			
			var pan = (i % 2 == 0) ? pct:  pct;
			
			setOrientation(index,  -pct, -45, 0);	
			setGobo(index, 1.0);
		}
		
		
	}
	
	
	
}