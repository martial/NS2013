var BOX = Animation.extend({

    setup: function (s) {

        println("-- BOX.js -- ");

        this._super();

    },

    update: function (s) {

//this.z = 0;
//this.z ++;
//var pct= 0,5+math.cos(this.z/100)*0,5;
//println(pct)
        //gauche

        for (var i = 0; i < 16; i += 2) {

            var index = horizontalSharpies[i];
            var nextIndex = horizontalSharpies[i];

            var currentPos = getSharpyPos(s, i);
            //var nextPos     = getSharpyPos(s, i+2);

            //lookAt(s, index, nextPos.x, nextPos.y, depth);
            lookAt(s, nextIndex, currentPos.x, currentPos.y, depth);

        }

        setOrientation(s, 17, 0, -90, 90);
        setOrientation(s, 19, 0, -90, 90);
        setOrientation(s, 21, 0, -90, 90);
        setOrientation(s, 23, 0, -90, 90);
        setOrientation(s, 25, 0, -90, 90);
        setOrientation(s, 27, 0, -90, 90);
        setOrientation(s, 29, 0, -90, 90);
        setOrientation(s, 31, 0, -90, 90);

        forceLight(s, 8, 0);
        forceLight(s, 9, 0);
        forceLight(s, 10, 0);
        forceLight(s, 11, 0);
        forceLight(s, 12, 0);
        forceLight(s, 13, 0);
        forceLight(s, 14, 0);
        forceLight(s, 15, 0);

        //setOrientation(s, 8, 0,0,-1  );
        //setBrightness   (s, 8,.5);

    }
});

new BOX();

