var Birdz = Animation.extend({

    setup: function (s) {

        println("-- Birdz -- ");
        this._super();
        
        this.pointY = 100;
        this.sens = -1;
        


    },

    update: function (s) {
        


      for ( var i=0; i<16; i++ ) {

          var angle = i * 180 / 16;
          if(i%2 == 0) angle = 180 - angle;
          setRotation(s, leftSharpies[i], 180, -90 + angle);

      }

        for ( var i=0; i<16; i++ ) {

            var angle = i * 180 / 16;
            if(i%2 == 0) angle = 180 - angle;
            setRotation(s, rightSharpies[i], 0, -90 + angle);

        }

    }
});


new Birdz();

