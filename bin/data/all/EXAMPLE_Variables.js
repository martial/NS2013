var ExampleVariables = Animation.extend({

    setup: function (s) {

        println("-- Example variables.js -- ");

        this._super();

        // pour définir des variables toujours utiliser this. avant
        // sinon les variables seront globales (i.e. utilisables partout )
        // et il y aura des conflits

        this.randomPositions    = new Array();
        this.time               = 0;
        this.maxTime            = 100;
        this.generateRandom();



    },

    /*

    Ici je crée une fonction qui appartient a mon animation
    Je pourrais l'appeler dans ma classe en faisant : this.generateRandom();

     */

    generateRandom: function () {

        for (var i = 0; i < numSharpy; i++) {

            this.randomPositions[i] = Math.random() * depth;

        }

    },

    update: function (s) {

        this.time++;

        println(this.time);

        if(this.time > this.maxTime) {
            this.generateRandom();
            this.time = 0;
        }




        for (var i = 0; i < numSharpy; i++) {

            lookAt(s, i, 0,0, this.randomPositions[i])

            
        }

    }
});


new ExampleVariables();


