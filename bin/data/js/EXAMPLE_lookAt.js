var ExampleLookAt = Animation.extend({

    setup: function (s) {

        println("-- Example LookAt.js -- ");

        this._super();

    },

    update: function (s) {




        for (var i = 0; i < numSharpy; i++) {


            // la fonction look at nous permet d'orienter le sharpy vers un point donné dans l'espace

            // note : l'origine est au centre de l'installation

            // s        = scene ( ne pas toucher )
            // i        = index sharpy
            // 0,0,0    = x, y, z

            // dans cette example j'utilise la variable globale "depth" qui nous permets de situer le sol

            // donc tous les sharpyes pointent à l'origine, au sol

            lookAt(s, i, width, height, depth);


        }

    }
});


new ExampleLookAt();


