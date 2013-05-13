var DOUBLE_STAIRWAY = Animation.extend({

    setup: function (s) {

        println("-- DOUBLE_STAIRWAY.js -- ");

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
 
setOrientation (s,16,0,  -600, -200)
setOrientation (s,17,0,  -579, -175)
setOrientation (s,18,0,  -558, -162.5)
setOrientation (s,19,0,  -537, -150)
setOrientation (s,20,0,  -516, -137.5)
setOrientation (s,21,0,  -495, -125)
setOrientation (s,22,0,  -474, -112.5)
setOrientation (s,23,0,  -453, -100)
setOrientation (s,24, 0, -432, -100)
setOrientation (s,25, 0, -411, -112.5)
setOrientation (s,26, 0, -390, -125)
setOrientation (s,27, 0, -369, -137.5)
setOrientation (s,28, 0, -348, -150)
setOrientation (s,29, 0, -327, -162.5)
setOrientation (s,30, 0, -306, -175)
setOrientation (s,31,0, -300, -200)

setOrientation (s,0,0,  600, -200)
setOrientation (s,1,0,  579, -175)
setOrientation (s,2,0,  558, -162.5)
setOrientation (s,3,0,  537, -150)
setOrientation (s,4,0,  516, -137.5)
setOrientation (s,5,0,  495, -125)
setOrientation (s,6,0,  474, -112.5)
setOrientation (s,7,0,  453, -100)
setOrientation (s,8, 0, 432, -100)
setOrientation (s,9, 0, 411, -112.5)
setOrientation (s,10, 0, 390, -125)
setOrientation (s,11, 0, 369, -137.5)
setOrientation (s,12, 0, 348, -150)
setOrientation (s,13, 0, 327, -162.5)
setOrientation (s,14, 0, 306, -175)
setOrientation (s,15,0, 300, -200)







    }
});




new DOUBLE_STAIRWAY();

