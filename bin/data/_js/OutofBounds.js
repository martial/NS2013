var Template = Animation.extend({

    setup: function (s) {

        println("-- OutOfBounds.js -- ");
        this._super();



    },

    update: function (s) {



        for (var i = 0; i < numSharpy; i++) {

           var step = Math.floor(4 * i / 32 );




           if(step == 0 ) {

               lookAt(s, i, -width, -height, 0);

           }

            if(step == 1 ) {

                lookAt(s, i, width, -height, 0);

            }

            if(step == 2 ) {

                lookAt(s, i, -width, height, 0);

            }

            if(step == 3 ) {

                lookAt(s, i, width, height, 0);

            }

            //lookAt(s, i, x, y, 0);
            //lookAt(s, indexN, x, y, 0);

        }

    }



});


new Template();




