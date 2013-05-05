var SUNSHINE = Animation.extend({

    setup: function (s) {

        println("-- SUNSHINE.js -- ");

        this._super();





    },

    update: function (s) {
    
//this.z = 0;
//this.z ++;
//var pct= 0,5+math.cos(this.z/100)*0,5;
//println(pct)
	//gauche
        
	setOrientation(s, 0, 0, 0,  depth);
	setOrientation(s, 1, 0, 0,  depth);
	setOrientation(s, 2, 0, 0,  depth);
	setOrientation(s, 3, -690, -75,  10);
	setOrientation(s, 4, -530, 75,  10);
	setOrientation(s, 5, -380, 150,  10);
	setOrientation(s, 6, -210, 225,  10);
	
	setOrientation(s, 7,-75, 300,  10);
	setOrientation(s, 8,75, 300,  10);
	    
	setOrientation(s, 9, 210, 225,  10);
	setOrientation(s, 10, 380, 150,  10);
	setOrientation(s, 11, 530, 75,  10);
	setOrientation(s, 12, 690, -75,  10);
	setOrientation(s, 13, 0, 0,  depth);
	setOrientation(s, 14, 0, 0,  depth);
	setOrientation(s, 15, 0, 0,  depth);
	
	//droite
	
	setOrientation(s, 16, 0, 0,  depth);
	setOrientation(s, 17, 0, 0,  depth);
	setOrientation(s, 18, 0, 0,  depth);
	setOrientation(s, 19, -690, 75,  10);
	setOrientation(s, 20, -530, -75,  10);
	setOrientation(s, 21, -380, -150,  10);
	setOrientation(s, 22, -210, -225,  10);
	
	setOrientation(s, 23,-75, -300,  10);
	setOrientation(s, 24,75, -300,  10);
	    
	setOrientation(s, 25, 210, -225,  10);
	setOrientation(s, 26, 380, -150,  10);
	setOrientation(s, 27, 530, -75,  10);
	setOrientation(s, 28, 690, 75,  10);
	setOrientation(s, 29, 0, 0,  depth);
	setOrientation(s, 30, 0, 0,  depth);
	setOrientation(s, 31, 0, 0,  depth);



      




        //setOrientation(s, 8, 0,0,-1  );
        //setBrightness   (s, 8,.5);


    }
});




new SUNSHINE();

