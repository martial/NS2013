var Triangles = Animation.extend({

    setup: function (s) {

        println("-- triangles.js -- ");

        //this._super();

    },

    update: function (s) {


        var isRow = true;

        var time    = timeMillis;
        var pct     = 0.5 + Math.cos(time / 1500) * 0.5;

        var range   = 2000;

        // loop into horizontal sharpies, and increase 2 each time
        for (var i = 0; i < horizontalSharpies.length; i+=2) {

            // get current index and next one
            var index       = horizontalSharpies[i];
            var nextIndex   = horizontalSharpies[i+1];


            // every two sharpies on horizontal - do something different
            // update current and next ( because we're i += 2 )
            if ( isRow ) {
                lookAt(s, index,        -range + (range*2 * pct),0,  (-150 ));
                lookAt(s, nextIndex,    -range + (range*2 * pct),0,  (-150 ));
            } else {

                setOrientation  (s, index, -45 , 0, 0);
                //setOrientation  (s, nextIndex, 45 , 0, 0);
            }

            setGobo         (s, index, 1.0);
            setBrightness   (s, index, 1.0);

            setGobo         (s, nextIndex, 1.0);
            setBrightness   (s, nextIndex, 1.0);

            // change
            isRow = !isRow;

        }

    }

});

new Triangles();

