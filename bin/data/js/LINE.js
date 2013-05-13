var LINE = Animation.extend({

    setup: function (s) {

        println("-- LINE.js -- ");

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

setOrientation (s,0,0, 180, depth)
setOrientation (s,16,0, -180, depth)
setOrientation (s,1,-150, 250, depth)
setOrientation (s,17,-150, -250, depth)
setOrientation (s,18,-300, -300, depth)
setOrientation (s,2,-300, 300, depth)

setOrientation (s,3, 0, 180, depth)
setOrientation (s,19, 0, -180, depth)
setOrientation (s,4, -150, 250, depth)
setOrientation (s,20, -150, -250, depth)
setOrientation (s,5, -300, 300, depth)
setOrientation (s,21, -300, -300, depth)

setOrientation (s,6, 0, 180, depth)
setOrientation (s,22, 0, -180, depth)
setOrientation (s,7, -150, 250, depth)
setOrientation (s,23, -150, -250, depth)
setOrientation (s,8, -300, 300, depth)
setOrientation (s,24, -300, -300, depth)

setOrientation (s,9, 0, 180, depth)
setOrientation (s,25, 0, -180, depth)
setOrientation (s,10, -150, 250, depth)
setOrientation (s,26, -150, -250, depth)
setOrientation (s,11, -300, 300, depth)
setOrientation (s,27, -300, -300, depth)

setOrientation (s,12, 0, 180, depth)
setOrientation (s,28, 0, -180, depth)
setOrientation (s,13, -150, 250, depth)
setOrientation (s,29, -150, -250, depth)
setOrientation (s,14, -300, 300, depth)
setOrientation (s,30, -300, -300, depth)

forceLight(s,31,0);
forceLight(s,15,0);






    }
});




new LINE();

