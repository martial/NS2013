var STAIRWAY1 = Animation.extend({

    setup: function (s) {

        println("-- STAIRWAY1.js -- ");

        this._super();





    },

    update: function (s) {
    
//this.z = 0;
//this.z ++;
//var pct= 0,5+math.cos(this.z/100)*0,5;
//println(pct)
	//gauche

        //setOrientation(s, 8, 0,0,-1  );
        //setBrightness   (s, 8,.5);
 
setOrientation (s,0,0,  600, 0)
setOrientation (s,1,0,  579, -12.5)
setOrientation (s,2,0,  558, -25)
setOrientation (s,3,0,  537, -37.5)
setOrientation (s,4,0,  516, -50)
setOrientation (s,5,0,  495, -62.5)
setOrientation (s,6,0,  474, -75)
setOrientation (s,7,0,  453, -87.5)
setOrientation (s,8, 0, 432, -100)
setOrientation (s,9, 0, 411, -112.5)
setOrientation (s,10, 0, 390, -125)
setOrientation (s,11, 0, 369, -137.5)
setOrientation (s,12, 0, 348, -150)
setOrientation (s,13, 0, 327, -162.5)
setOrientation (s,14, 0, 306, -175)
setOrientation (s,15,0, 300, -200)

forceLight(s,16, 0);
forceLight(s,17, 0);
forceLight(s,18, 0);
forceLight(s,19, 0);
forceLight(s,20, 0);
forceLight(s,21, 0);
forceLight(s,22, 0);
forceLight(s,23, 0);
forceLight(s,24, 0);
forceLight(s,25, 0);
forceLight(s,26, 0);
forceLight(s,27, 0);
forceLight(s,28, 0);
forceLight(s,29, 0);
forceLight(s,30, 0);
forceLight(s,31, 0);






    }
});




new STAIRWAY1();

