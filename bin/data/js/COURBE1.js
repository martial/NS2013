var COURBE1 = Animation.extend({

    setup: function (s) {

        println("-- COURBE1.js -- ");

        this._super();





    },

    update: function (s) {
    
//this.z = 0;
//this.z ++;
//var pct= 0,5+math.cos(this.z/100)*0,5;
//println(pct)
	//gauche
        
	lookAt(s, 0, -1130, 300,  depth);
	lookAt(s, 1, -990, 225,  depth);
	lookAt(s, 2, -820, 150,  depth);
	lookAt(s, 3, -690, 75,  depth);
	lookAt(s, 4, -530, -75,  depth);
	lookAt(s, 5, -380, -150,  depth);
	lookAt(s, 6, -210, -225,  depth);
	
	lookAt(s, 7,-75, -300,  depth);
	lookAt(s, 8,75, -300,  depth);
	    
	lookAt(s, 9, 210, -225,  depth);
	lookAt(s, 10, 380, -150,  depth);
	lookAt(s, 11, 530, -75,  depth);
	lookAt(s, 12, 690, 75,  depth);
	lookAt(s, 13, 820, 150,  depth);
	lookAt(s, 14, 990, 225,  depth);
	lookAt(s, 15, 1130, 300,  depth);
	
	//droite
	
	lookAt(s, 16, -1130, 300,  depth);
	lookAt(s, 17, -990, 225,  depth);
	lookAt(s, 18, -820, 150,  depth);
	lookAt(s, 19, -690, 75,  depth);
	lookAt(s, 20, -530, -75,  depth);
	lookAt(s, 21, -380, -150,  depth);
	lookAt(s, 22, -210, -225,  depth);
	
	lookAt(s, 23,-75, -300,  depth);
	lookAt(s, 24,75, -300,  depth);
	    
	lookAt(s, 25, 210, -225,  depth);
	lookAt(s, 26, 380, -150,  depth);
	lookAt(s, 27, 530, -75,  depth);
	lookAt(s, 28, 690, 75,  depth);
	lookAt(s, 29, 820, 150,  depth);
	lookAt(s, 30, 990, 225,  depth);
	lookAt(s, 31, 1130, 300,  depth);



      




        //lookAt(s, 8, 0,0,-1  );
        //setBrightness   (s, 8,.5);


    }
});




new COURBE1();

