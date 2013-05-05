var STAIRWAY2 = Animation.extend({

    setup: function (s) {

        println("-- STAIRWAY2.js -- ");

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
 
setOrientation (s,16,0,  -600, 0)
setOrientation (s,17,0,  -579, -12.5)
setOrientation (s,18,0,  -558, -25)
setOrientation (s,19,0,  -537, -37.5)
setOrientation (s,20,0,  -516, -50)
setOrientation (s,21,0,  -495, -62.5)
setOrientation (s,22,0,  -474, -75)
setOrientation (s,23,0,  -453, -87.5)
setOrientation (s,24, 0, -432, -100)
setOrientation (s,25, 0, -411, -112.5)
setOrientation (s,26, 0, -390, -125)
setOrientation (s,27, 0, -369, -137.5)
setOrientation (s,28, 0, -348, -150)
setOrientation (s,29, 0, -327, -162.5)
setOrientation (s,30, 0, -306, -175)
setOrientation (s,31,0, -300, -200)

forceLight(s,0, 0);
forceLight(s,1, 0);
forceLight(s,2, 0);
forceLight(s,3, 0);
forceLight(s,4, 0);
forceLight(s,5, 0);
forceLight(s,6, 0);
forceLight(s,7, 0);
forceLight(s,8, 0);
forceLight(s,9, 0);
forceLight(s,10, 0);
forceLight(s,11, 0);
forceLight(s,12, 0);
forceLight(s,13, 0);
forceLight(s,14, 0);
forceLight(s,15, 0);







    }
});




new STAIRWAY2();

