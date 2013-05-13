var SYDNEY_ROOF = Animation.extend({

    setup: function (s) {

        println("-- SYDNEY_ROOF.js -- ");

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

lookAt (s,0,-1050, -100, 0)
lookAt (s,1,-920, -50, 0)
lookAt (s,2,-800, 0, 0)
lookAt (s,3,-700, 50, 0)
lookAt (s,4,-600, 100, 0)
forceLight(s, 16, 0);
forceLight(s, 17, 0);
forceLight(s, 18, 0);
forceLight(s, 19, 0);
forceLight(s, 20, 0);
forceLight(s, 21, 0);

lookAt (s,5,-500, 150, 0)
setOrientation (s,21,0, -90, 0)
lookAt (s,22,-400, 100, 0)
lookAt (s,23,-300, 50, 0)
lookAt (s,24,-200, 0, 0)
lookAt (s,25,-100, -50, 0)
lookAt (s,26,0, -100, 0)
lookAt (s,27,100, -150, 0)
forceLight(s, 6, 0);
forceLight(s, 7, 0);
forceLight(s, 8, 0);
forceLight(s, 9, 0);


lookAt (s,10,200, -100, 0)
lookAt (s,11, 300, -50, 0)
lookAt (s,12, 400, 0, 0)
lookAt (s,13, 500, 50, 0)
lookAt (s,14, 600, 100, 0)
lookAt (s,15, 700, 150, 0)
forceLight(s, 28, 0);
forceLight(s, 29, 0);
forceLight(s, 30, 0);
forceLight(s, 31, 0);



    }
});




new SYDNEY_ROOF();

