function Queue(){
	//defining variables
	queue = [];
	rear = 0;

	//return the length of the queue
	this.getlength = function()
	{
		return (queue.length - rear);
	}

	//checks the empty state of the queue
	this.isEmpty = function()
	{
		return ( queue.length == 0);
	}

	//add an element to the queue
	this.enqueue = function(data)
	{
		queue.push(data);
	}

	//dequeue an element from the queue
	this.dequeue = function()
	{
		if(this.isEmpty())
		{
			return undefined;
		}
		var item = queue[rear];
	}
}
