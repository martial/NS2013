var ExampleBounds = Animation.extend({

    setup: function (s) {

        println("-- Example Bounds.js -- ");
        this._super();

    },

    update: function (s) {


        // cet example est juste pour montrer les variables de taille ( surtout utile pour lookAt )

        lookAt(s, 0, width, height, depth);
        lookAt(s, 15, -width, height, depth);

        lookAt(s, 16, width, -height, depth);
        lookAt(s, 31, -width, -height, depth);


        lookAt(s, 6, 0, 0, depth);
        lookAt(s, 25, 0, 0, depth);
        lookAt(s, 9, 0, 0, depth);
        lookAt(s, 22, 0, 0, depth);



    }
});


new ExampleBounds();


