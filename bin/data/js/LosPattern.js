var LosPattern = Animation.extend({

    setup: function (s) {

        println("-- CrossHouse -- ");
        this._super();

        


    },

    update: function (s) {


        for ( var i=0; i<16; i++ ) {

            var pos = getSharpyPos(s, rightSharpies[15-i]);
            lookAt(s, i, pos.x, pos.y + (i*50), depth - (i*40))

        }

        for ( var i=0; i<16; i++ ) {

            var pos = getSharpyPos(s, 15-i);
            lookAt(s, rightSharpies[i], pos.x, pos.y - (i*50), depth - (i*40))



        }



    }
});


new LosPattern();

