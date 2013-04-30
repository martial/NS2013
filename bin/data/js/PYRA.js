var PYRA = Animation.extend({

    setup: function (s) {

        println("-- PYRA.js -- ");

        this._super();





    },

    update: function (s) {
    
//this.z = 0;
//this.z ++;
//var pct= 0,5+math.cos(this.z/100)*0,5;
//println(pct)

      forceLight(s, 1, 0);
      forceLight(s, 17, 0);
      forceLight(s, 30, 0);
      forceLight(s, 14, 0); 
	lookAt(s, 0, -900, 10,  depth);

lookAt(s, 3, -900, 10,  depth);
              
lookAt(s, 16, -900, 10,  depth);

lookAt(s, 19, -900, 10,  depth);
        
	lookAt(s, 4, -320, 10,  depth);

lookAt(s, 7, -320, 10,  depth);
              
lookAt(s, 20, -320, 10,  depth);

lookAt(s, 23, -320, 10,  depth);

	lookAt(s, 8, 310, 10,  depth);

lookAt(s, 11, 310, 10,  depth);
              
lookAt(s, 24, 310, 10,  depth);

lookAt(s, 27, 310, 10,  depth);


	lookAt(s, 12, 900, 10,  depth);

lookAt(s, 15, 900, 10,  depth);
              
lookAt(s, 28, 900, 10,  depth);

lookAt(s, 31, 900, 10,  depth);


	lookAt(s, 6, 0, 10,  depth);

lookAt(s, 9, 0, 10,  depth);
              
lookAt(s, 22, 0, 10,  depth);

lookAt(s, 25, 0, 10,  depth);

	lookAt(s, 2, -650, 10,  depth);

lookAt(s, 5, -650, 10,  depth);
              
lookAt(s, 18, -650, 10,  depth);

lookAt(s, 21, -650, 10,  depth);

		lookAt(s, 10, 660, 10,  depth);

lookAt(s, 13, 660, 10,  depth);
              
lookAt(s, 26, 660, 10,  depth);

lookAt(s, 29, 660, 10,  depth);



      




        //lookAt(s, 8, 0,0,-1  );
        //setBrightness   (s, 8,.5);


    }
});




new PYRA();

