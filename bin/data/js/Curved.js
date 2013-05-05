var Curved = Animation.extend({

    setup: function (s) {

        println("-- CrossHouse -- ");
        this._super();
        

        


    },

    update: function (s) {


        for ( var i=0; i<32; i++ ) {

            var pos = getSharpyPos(s, 31-i);
            lookAt(s, i, -width / 2 + pos.x + i * 70, -height + pos.y + i * 40, 0)

        }




    }
});


new Curved();

