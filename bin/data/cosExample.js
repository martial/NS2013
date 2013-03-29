


function setup (s) {
	
	println("-- circle example.js -- ");
	var time = of.GetElapsedTimeMillis();
	
	for ( var i=0; i<2; i++) {
		
		for (var j=0; j<16; j++) {
			
			var index = i * 16 + j;
			var posSharpy = new fk.Vec3(getPosX(index), getPosY(index), 0);


			//lookAt(s, index,  getMouseX(), 0, -300);
			//setGobo(s, index,  .5);	
			
		} 
		
		
	}
	
	
}


/*
function angle2D(a, b) {

	return Math.atan2( a.x*b.y-a.y*b.x, a.x*b.x + a.y*b.y )* * (180.0/Math.PI);
}


function angle(a, b) {
	
	a.normalize();
	b.normalize();
	
	return 90 + Math.acos( dot(a,b) ) * (180.0/Math.PI);
		
}

function dot(a, b) {
		
	return 		a.x * b.x + 
				a.y * b.y + 
				a.z * b.z;
}

*/
 

function update (s, time) {
	
	var time = of.GetElapsedTimeMillis();
	var pct = 0.5 + Math.cos(time / 500) * 0.5;
	var radius = ( 300 * pct);
	var a= (Math.PI * 2.0) / numSharpy;
	

	for ( var i=0; i<2; i++) {
		
		for (var j=0; j<16; j++) {
			
			
			var index = i * 16 + j;
			var cnt = ( i ==0 ) ? (16 + index) :  (32 - index);
			var yo = 0.5 + Math.cos( (time + index * 14) / 50) * 0.5;
			
			x = Math.cos(cnt * a) * radius;
			y = Math.sin(cnt * a) * radius;
			
			//var r = 400;
			//x += ( -r + ( r*2 * pct));
			//y += ( -r + ( r*2 * pct));
			//var posSharpy = new fk.Vec3(getPosX(index), getPosY(index), 0);
			
			lookAt(s, index,   x, y, -300 );
			setGobo(s, cnt,  yo);
			setBrightness(s, cnt, 1);	
			
		}
		
		}
		
	
}