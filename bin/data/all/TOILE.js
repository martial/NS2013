var TOILE = Animation.extend({

    setup: function (s) {

        println("-- TOILE.js -- ");
        this._super();

    },

    update: function (s) {for (var i = 0; i < numSharpy; i++) {

            // setRotation change le pan et tilt du sharpy

            // s            = scene ( ne pas toucher )
            // i            = sharpy index

            // rotationX    = minimum : 0   maximum : 360
            // rotationY    = minimum : -90 maximum : 90

            // dans cet example on varie de 0 à 360 le tilt selon l'index du sharpy

            var rotationX = i * 180 / numSharpy;
            var rotationY = 90;

            setRotation(s, i, rotationX, rotationY);

                      
            
        
}
    }
});


new TOILE();


