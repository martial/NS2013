var Template = Animation.extend({

    setup: function (s) {

        println("-- AHOU.js -- ");
        this._super();

        this.yoyo = new yoyo();
        this.yoyo.init();

        for (var i = 0; i < numSharpy; i++) {
            //
        }

    },

    update: function (s) {

        this.yoyo.update();

        for (var i = 0; i < numSharpy; i++) {

            var index = horizontalSharpies[i];


            var pan = (i % 2 == 0 ) ? 20 : -45;

            //setOrientation  (s, index, pan, 0, 0);
            lookAt          (s, i, 0,0, -150);
            setGobo         (s, i, 0.2);
            setBrightness   (s, i, 1);

        }

    }
});


new Template();


