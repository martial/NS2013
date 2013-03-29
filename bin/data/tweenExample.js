


function setup (s) {
		
	println("-- tween example.js -- ");
	// reset tweens
	this.tweens = new Array();	
	TWEEN.removeAll();
	 
		 
	this.goMadCount = 0;
	this.openArmsCount = 0;
	this.turtleCount = 0 ;
	this.cosPct = 0.0;
	this.scene = s;
	
	// start
	this.initTweens (s); 
	
} 




function initTweens () {
	
	//TWEEN.removeAll();
	

	for ( var i=0; i<2; i++) {
		
		for (var j=0; j<16; j++) {
			
			// get index
			var index = i * 16 + j;
			
			// get simple orientation
			var pan = (i % 2 == 0) ? -45 :  45;
			 
			// set default orientation - be careful It's for testing
			setOrientation(scene, index, 0, 0, 0);	
			 
			// add a new empty orientation - push it to array
			this.tweens[index] = {brt: 1.0, gobo:1.0, pan:0, tilt:0, roll:0};
			
			    
			// declare our tweens !
			// let's rumble the pan titl and gobo.
						
			 var tween = new TWEEN.Tween( tweens[index] )
		            .to( { pan: pan, gobo:1.0, tilt:45, brt:1.0 }, 500 + (j * 10) )
		            .easing( TWEEN.Easing.Quintic.Out )
		            //.onUpdate( function () { // do as you please } )
		            .start(); 
		            
		            
		     // if It's the last one, then goLaser       
		     if(index == 31) 
			     tween.onComplete(function(){goLaser ()});
		     

		}
		
	}	
	 
} 

function goLaser () {
	
	//TWEEN.removeAll();
	println("---"); 
		
	for ( var i=0; i<2; i++) {
	
		for (var j=0; j<16; j++) { 
		
		var index = i * 16 + j;
		var pan = (i % 2 == 0) ? 45 :  -45;
		
		
		//if(index==0)
		//println(this.tweens);
		
		var tween = new TWEEN.Tween(this.tweens[index])
		            .to( {pan:pan, gobo:0.0, tilt:-45} , 300 + (j * 200) )
		            .easing( TWEEN.Easing.Quintic.InOut )
		            .start(); 

		 }
		 
		 if(index == 31  ) 
		     tween.onComplete(function(){goMad()});	
		    
		   	     
	}
	
	goMadCount++;
	
	
	
}

function goMad () {
	
	
	for ( var i=0; i<numSharpy; i++) {
		
		var rdm 	= Math.random();
		var pan 	= -45 + (90*rdm);
		var tilt 	= -45 + (90*rdm);
		var roll 	= -45 + (90*rdm);
		var speed 	= 2000 + rdm * 400;
		
		var tweenObject = this.tweens[i];
		var tween = new TWEEN.Tween(this.tweens[i])
		            .to( {pan:pan, tilt:tilt, roll:roll} , speed )
		            .easing( TWEEN.Easing.Linear.None )
		            .onUpdate(strob)
		            .start();
		            
		  if(i == 31 && goMadCount < 4 ) 
		     tween.onComplete(function(){goMad()});	
		     else if (i == 31) {
		     	tween.onComplete(function(){goFront()});	
		     	goMadCount = 0;
		     	}
		  }
		  
		  goMadCount++;
}


function goFront() {
	
	
	for ( var i=0; i<numSharpy; i++) {
		
		var tween = new TWEEN.Tween(this.tweens[i])
		            .to( {pan:0, tilt:-70, roll:0} , 2000 )
		            .easing( TWEEN.Easing.Linear.None )
		            .onUpdate(strob)
		            .start();
		            
		  if(i == 31 ) 
		     tween.onComplete(function(){goCloseArms()});	
		     
	  }
		  	
	
}

function goCloseArms() {
	
	
	for ( var i=0; i<2; i++) {
	
		for (var j=0; j<16; j++) { 
		
		var index = i * 16 + j;
		var pan = (i % 2 == 0) ? 12 :  -12;
		
		var tween = new TWEEN.Tween(this.tweens[index])
		            .to( {pan:pan, tilt:-70, roll:0} , 2000 )
		            .easing( TWEEN.Easing.Linear.None )
		            .onUpdate(strob)
		            .start();
		            
		  if(index == 31 ) 
		     tween.onComplete(function(){goPapillonDeLumiere()});
		     
		     	
			}     
	  }
		  	
	
}

function goPapillonDeLumiere() {
	
	
	for ( var i=0; i<2; i++) {
	
		for (var j=0; j<16; j++) { 
		
		var index = i * 16 + j;
		var pan = (i % 2 == 0) ? -j*3 :  j*3;
		
		var tween = new TWEEN.Tween(this.tweens[index])
		            .to( {pan:pan, tilt:-70, roll:0} , 2000 )
		            .easing( TWEEN.Easing.Linear.None )
		            .onUpdate(strob)
		            .start();
		            
		   if(index == 31 && openArmsCount < 4 ) 
		     tween.onComplete(function(){goPapillonDeLumiere()});	
		     else if (index == 31) {
		     	tween.onComplete(function(){doTheTurtle()});	
		     	goMadCount = 0;
		     	}
		  }
 
	  }
		  	 
	openArmsCount ++;
}

function doTheTurtle () {


	var tween = new TWEEN.Tween({dummy:0})
		            .to( {dummy:1} , 10000 )
		            .easing( TWEEN.Easing.Linear.None )
		            .onUpdate(function () {
		            	renderTurtle()
		            })
		            .start();
	
	
	  
}

function renderTurtle () {
	
	
	for ( var i=0; i<2; i++) {
	
		for (var j=0; j<16; j++) { 
		
		var index = i * 16 + j;
		cosPct = 0.5 + Math.cos(of.GetElapsedTimeMillis() + j / 6 / 1000) * 0.5;
		var pan = (i % 2 == 0) ? -50 + ( j * cosPct  ) :  50 + ( -j * cosPct);
		
		
				
		this.tweens[index].pan = pan;
				
		}
	  }
}

function goClose() {
	
	
	for ( var i=0; i<2; i++) {
	
		for (var j=0; j<16; j++) { 
		
		var index = i * 16 + j;
		var pan = (i % 2 == 0) ? -j*2 :  j*2;
		
		var tween = new TWEEN.Tween(this.tweens[index])
		            .to( {pan:0, tilt:0, roll:0, brt:0.0} , j * 100 )
		            .easing( TWEEN.Easing.Linear.None )
		            .onUpdate(strobGobo)
		            .start();
		            
		  if(index == 31 ) 
		     tween.onComplete(function(){initTweens ()});
		     
		     	
			}     
	  }
		  	
	
}

function strobGobo(object) {
	object.gobo = 	Math.random();
	
}


function strob(object) {
	object.gobo = 	Math.random();
	object.brt	=	Math.random();
	
}

function update (s) {
	
	
	// update Tween engine
	this.TWEEN.update();
	
	//cosPct = 0.5 + Math.cos(time / 6) * 0.5;

	
	// update sharpys properties
	for ( var i=0; i<numSharpy; i++) {
	
		var tween = this.tweens[i];
		
		setOrientation(s, i,tween.pan, tween.tilt, tween.roll);	
		setGobo(s, i, tween.gobo);
		setBrightness(s, i, tween.brt)
								
	}	
	
	
	
	/*
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
	
	*/
	
}