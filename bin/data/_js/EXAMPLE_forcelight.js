var ExampleForceLight = Animation.extend({

    setup: function (s) {

        println("-- Template.js -- ");
        this._super();



    },

    update: function (s) {



        for (var i = 0; i < numSharpy; i++) {

            // un sur deux je force l'extinction

            if( i % 2 == 0 )
                forceLight(s, i, 0);

            /*

            Attention je peux aussi forcer l'allumage dans tous les cas
            dans ce cas plus rien ne sera animé

             */

            //else
               // forceLight(s, i, 1);


        }

    }


});


new ExampleForceLight();




