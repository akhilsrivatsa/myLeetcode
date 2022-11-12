class MedianFinder {
    
    PriorityQueue<Integer> minQueue = new PriorityQueue<>();
    PriorityQueue<Integer> maxQueue = new PriorityQueue<>(Collections.reverseOrder());
    
    public MedianFinder() {
        
        
       
        
    }
    
    public void addNum(int num) {
        
        if(maxQueue.isEmpty() || num <= maxQueue.peek()){
            maxQueue.add(num);
        }else{
            minQueue.add(num);
        }
        
        
        if(minQueue.size() > maxQueue.size()){
            maxQueue.add(minQueue.poll());
        }
        
        if(maxQueue.size() > minQueue.size() + 1){
            minQueue.add(maxQueue.poll());
        }
        
    }
    
    public double findMedian() {
        
        if((maxQueue.size() + minQueue.size()) % 2 == 0){
            
            
            double ans = minQueue.peek() + maxQueue.peek();
           // System.out.println("ans : " + ans);
            
            return ans / 2;
        }
        
        return maxQueue.peek();
        
    }
}

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */