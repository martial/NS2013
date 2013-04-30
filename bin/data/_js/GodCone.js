var GodCone = Animation.extend({

    setup: function (s) {

        println("-- test Bounds.js -- ");
        this._super();
        this.arr = new Array(0, 15, 16, 31, 6, 25, 9, 22);

    },

    update: function (s) {


        // cet example est juste pour montrer les variables de taille ( surtout utile pour lookAt )




        for ( var j=0; j<32; j++) {



            if (!this.inArray(j)) {


                lookAt(s, j, 0,0,depth * speedPct);


            } else {
                lookAt(s, j, 0,0,depth );
            }

        }





    },

    inArray : function (id) {

        for (var i=0; i<this.arr.length; i++) {
            if(this.arr[i] == id) return true;

        }

        return false;
    }
});


new GodCone();


