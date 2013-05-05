var VAGUE = Animation.extend({

    setup: function (s) {

        println("-- VAGUE.js -- ");
        this._super();
        this.counter=0
        this.speed=1
       
        
    },

    update: function (s) {
    
    this.counter++;
    
    
    for (var x = 16; x< 32; x++){
    
	    var rotY = (0.5 + Math.cos(x + this.counter)*0.5)*-100;
	    
	   setRotation(s, x, 0, rotY ); 
	    
    }
    
    for (var x = 0; x< 16; x++){
    
	    var rotY = (0.5 + Math.cos(x + this.counter)*0.5)*100;
	    
	   setRotation(s, x,0, rotY ); 
	    
    }
    
    }
});


new VAGUE();


