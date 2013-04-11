var Condor = Animation.extend({

    setup: function (s) {

        println("-- Le condor.js -- ");

        this._super();
        this.easedPct = new EasedPct(true);
        this.easedPct.init(true);

    },

    update: function (s) {

        this.easedPct.update();

        var maxPan      = 80;

        for (var i = 0; i < leftSharpies.length; i++) {

            //setOrientation  (s, i, 0, 0, 0);
            var index       = leftSharpies[i];
            var brtPct      = (i % 2 == 0) ? 1.0 : 1.0;
            var goboPct     = normalize(i, leftSharpies.length);

            var pan =  this.easedPct.pct  * -maxPan + i *2;
            setOrientation  (s, index, pan , 0, 0);
            setGobo         (s, index, goboPct);
            setBrightness   (s, index, brtPct);

        }

        for (var i = 0; i < rightSharpies.length; i++) {


            //println("time " + time);
            //setOrientation  (s, i, 0, 0, 0);
            var index       = rightSharpies[i];
            var brtPct      = (i % 2 == 0) ? 1.0 : 1.0;
            var goboPct     = normalize(i, rightSharpies.length);

            var pan = this.easedPct.pct * maxPan - i *2;

            setOrientation  (s, index, pan , 0, 0);
            setGobo         (s, index, goboPct);
            setBrightness   (s, index, brtPct);

        }

    }

});

new Condor();


var EasedPct = fk.Class.extend({


    init:function(yoyo) {


        this.beginning  = 0.0;
        this.end        = 1.0;

        this.pct        = 0.0;
        this.time       = 0.0;
        this.max        = 1.0;

        this.isYoyo     = yoyo;

        this.sens       = 1.0;

    },

    update:function() {

        //this.pct = this.easeInOut(this.time, this.beginning, this.end, 1.0);



        if (!this.isYoyo ) {

            if (this.time > 1.0) {
                this.sens = -1.0;
            }

            if (this.time < 0.0) {
                this.sens = 1.0;
            }

        } else {
            if (this.time > 1.0)
            this.time = 0.0;
        }

        this.pct = this.easeInOut(this.time, this.beginning, this.end, 1.0);

        this.time += 0.05 * speedPct * this.sens;


    },

    linear:function (t, b , c,  d) {

        return c*t/d + b;
    },

    easeInOut: function ( t, b ,  c,  d) {
        if ((t/=d/2) < 1) return c/2*t*t*t + b;
        return c/2*((t-=2)*t*t + 2) + b;
    }



})/**
 * Created with JetBrains PhpStorm.
 * User: martialou
 * Date: 08/04/13
 * Time: 18:15
 * To change this template use File | Settings | File Templates.
 */
