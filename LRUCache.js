class Node
{
    /* Doubly linked list */
    constructor(key, value, next, prev)
    {
        this.key = key
        this.value = value
        this.next = next
        this.prev = prev
    }
}

/* Cache is a double ended queue of doubly linked list nodes */
class LRUCache{

    constructor(maxSize)
    {
        this.size = 0
        this.maxSize = maxSize
        this.front = null
        this.back = null
        /* To access the value of the key in O(1) time store the address of node into cacheMap */
        this.cacheMap = new Map()
    }

    getNodeRef(key){
        return this.cacheMap.get(key)
    }

    /* Add the node to thr front of the queue */
    addToFront(key, value)
    {
        /* Create the new Node and add it to the fron of the dequeue as it is the most frequent node now */
        let newNode = new Node(key, value, this.front, null)
        newNode.next = this.front
        if(this.front != null) this.front.prev = newNode
        this.front = newNode
        /* Set the memory ref for the node with with given key */
        this.cacheMap.set(key, this.front)
        if(this.size == 0) this.back = this.front
        this.size += 1
    }

    /* Inserts the value of the key passed */
    put(key,value)
    {
        /* If key is already present then update the value */
        if(this.cacheMap.has(key))
        {
            let nodeRef = this.cacheMap.get(key)
            /* Delete this node from dequeue and also from cacheMap*/
            this.delete(key, nodeRef)
        }   
        /* Key is already not present  and If cache is full */
        else if(this.size >= this.maxSize )
        {
            /* First delete the Least recently used node of the dequeue */
            /* Least recently used node would be at the back of the dequeue */
            let nodeRef = this.cacheMap.get(this.back.key)
            /* Delete the node from queue and the cacheMap */
            this.delete(this.back.key, nodeRef)
        }
        /* Key is not already not present in the queue */
            this.addToFront(key, value)

    }

    get = (key)=> {
        /* If key is already present in the queue */
        if(this.cacheMap.has(key)){
            /* returns the value for the given key */ 
            let nodeRef = this.cacheMap.get(key)
            return nodeRef.value
        }
        /* If key is not present in the queue */
        return -1;
    }

    /* Deletes Least recently used node from the dequeue */
    delete(key, nodeRef)
    {
        if(nodeRef){
            if(nodeRef.prev != null) nodeRef.prev.next = nodeRef.next
            else this.front = nodeRef.next
            if(nodeRef.next != null)  nodeRef.next.prev = nodeRef.prev
            else this.back = nodeRef.prev
            /* Remove the key from cacheMap */
            this.cacheMap.delete(key)
            this.size -= 1
        }
    }

    display(){
        let head = this.front
        while(head != null){
            console.log(head.key + " -> " + head.value)
            head = head.next
        }
    }
}

const lruCache = new LRUCache(3)
lruCache.put(2, 10)
lruCache.put(5, 20)
lruCache.put(3, 30)
lruCache.display()
lruCache.put(4,50)
console.log("\n")
lruCache.display()
let keyValue = lruCache.get(2)
console.log(keyValue + " " + lruCache.size)

