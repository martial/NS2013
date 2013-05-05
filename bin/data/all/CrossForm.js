var CrossForm = Animation.extend({

    setup: function (s) {

        println("-- CrossForm.js -- ");
        this._super();

        this.sharpies = new Array (
            {x:24, y:4},
            {x:20, y:8},
            {x:29, y:9},
            {x:25, y:13}

        );

    },

    inArray : function (id) {

        for (var i=0; i<this.sharpies.length; i++) {

            var sharpyObj = this.sharpies[i];
            if(sharpyObj.x == id || sharpyObj.y == id) return true;

        }

        return false;
    },

    update: function (s) {

        for (var i=0; i<this.sharpies.length; i++) {

            var sharpyObj = this.sharpies[i];

            var pos = getSharpyPos(s, sharpyObj.x);
            lookAt(s, sharpyObj.y, pos.x, 0, depth/2 );

            pos = getSharpyPos(s, sharpyObj.y);
            lookAt(s, sharpyObj.x, pos.x, 0,  depth/2);

        }


        for (var i = 0; i < numSharpy; i++) {
                if(!this.inArray(i))
                    forceLight(s, i, 0);
        }

    }

});


new CrossForm();




