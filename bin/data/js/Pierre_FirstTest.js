var PierreFirstTest = Animation.extend({

    setup: function (s) {

        println("-- Hello -- ");
        this._super();
        
        this.pointY = 100;
        this.sens = -1;
        


    },

    update: function (s) {
        

        
        
         if(!this.pointY) 
            this.pointY = 100;
        
         if(!this.sens) 
            this.sens = 1;
        
        //var pointX = 0;//width*speedPct*2  -width/2;
        //var pointY = 100;//height*speedPct*2 -height/2;
        //var pointZ = depth*speedPct;
        
        /*
        setRotation(s, leftSharpies[1], rotationX, rotationY);
        setRotation(s, rightSharpies[1], rotationX*-1, rotationY*-1);
        */
        
        /*lookAt(s, 0, pointX, pointY, pointZ);
        lookAt(s, 15, pointX, pointY, pointZ);

        lookAt(s, 16, pointX, pointY, pointZ);
        lookAt(s, 31, pointX, pointY, pointZ);*/
        
        if(this.pointY <= -100 )
        {
            this.sens = 1;
        }
        else if( this.pointY >= 100)
        {
            this.sens = -1   
        }
        
       
        
        this.pointY += this.sens;
        
        lookAt(s, 8, 0, this.pointY, depth);
        
        lookAt(s, 0, 0, this.pointY, depth);
        
        lookAt(s, 12, 0, this.pointY, depth);
    
        //println("PY: "+ this.pointY);
        
        var pos = getSharpyPos(s, 20);
        
        //lookAt(s, 3, pos.x, pos.y, pos.z);

    }
});


new PierreFirstTest();

