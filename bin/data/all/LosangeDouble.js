var UpTriangle = Animation.extend({

    setup: function (s) {

        println("-- LosangeCorrect.js -- ");
        this._super();



    },

    update: function (s) {




        for (var i = 0; i < numSharpy; i++) {

            var step = Math.floor(2 * i / 32 );

            var globalPct =  speedPct;


            if(step == 0 ) {

                var pct     = normalize(i, 8);
                var xPos    = -width + (width * pct);
                var yPos    = -height * pct;

                if(i >8 ) {

                     xPos    = xPos
                     yPos    = -height * 2 -yPos

                }


                if(i %2 == 0 ) globalPct *= 0.4;

                xPos *= globalPct;
                yPos *= globalPct;

                lookAt(s, i, xPos, yPos, depth);

            }

            if(step == 1 ) {

                var pct     = normalize(15 - i, 8);
                var xPos    =  -width + - (width * pct);
                var yPos    = -height * pct;

                if(31 - i < 8) {

                    xPos    =  + xPos
                    yPos    = height * 2 -yPos

                }

                if((31 - i) %2 == 0 ) globalPct *= 0.4;

                xPos *= globalPct;
                yPos *= globalPct;

                lookAt(s, i, xPos, yPos, depth);

                //lookAt(s, i, width, -height, 0);

            }


        }


    }



});


new UpTriangle();




