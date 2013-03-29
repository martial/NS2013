var Template = Animation.extend({

    setup: function (s) {

        println("-- Template.js -- ");
        this._super();

        for (var i = 0; i < numSharpy; i++) {
            //
        }

    },

    update: function (s) {

        for (var i = 0; i < numSharpy; i++) {


            //setOrientation  (s, i, 0, 0, 0);
            lookAt          (s, i, 0, 0, -300);
            setGobo         (s, i, 1);
            setBrightness   (s, i, 1);


        }

    }

});

new Template();

