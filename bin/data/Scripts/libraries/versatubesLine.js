// ----------------------------
// Line
function Line(def)
{
	var A_ = versatubes.getPoint(def[0],def[1]);
	var B_ = versatubes.getPoint(def[2],def[3]);
	
	this.A = new fk.Vec2(A_.x,A_.y);
	this.B = new fk.Vec2(B_.x,B_.y);
	this.P = new fk.Vec2(this.B.x,this.B.y);
	
	this.t = 1;
	this.tween = null;

	this.display = function()
	{
		of.Line(this.A.x,this.A.y,this.P.x,this.P.y);
	}

	this.animate = function(duration)
	{
		if (this.tween)
			this.tween.stop();
		this.tween = new Tween(this, "t", "", 0, 1, duration);
		this.tween.start();
	}

	this.update = function()
	{
		if (this.tween){
			this.tween.tick();
			this.P.lerp(this.B, this.t);
		}
	}

}



