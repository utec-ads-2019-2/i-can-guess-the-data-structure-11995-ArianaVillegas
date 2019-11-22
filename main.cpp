#include <iostream>
#include <queue>
#include <stack>

int main(){
    int number,i,op,n;
    bool queue,stack,prio_queue;
    while(scanf("%d",&number)==1){
	queue=1,stack=1,prio_queue=1;
	std::queue<int> q;
	std::stack<int> s;
	std::priority_queue<int> p;
	for(i=0;i<number;++i){
	    scanf("%d %d",&op,&n);
            if(op==1){
	        p.push(n);
	        q.push(n);
	        s.push(n);
	    }else if(op==2){
		if(queue){
		    if(q.empty() || q.front()!=n)
 		        queue=0;
		    else
			q.pop();
		}
		if(stack){
		    if(s.empty() || s.top()!=n)
 		        stack=0;
		    else
			s.pop();
		}
		if(prio_queue){
		    if(p.empty() || p.top()!=n)
		        prio_queue=0;
		    else
			p.pop();
		}
	    }		
	}
	if(!queue && !stack && !prio_queue) std::cout << "impossible\n";
	else if(queue && !stack && !prio_queue) std::cout << "queue\n";
	else if(!queue && stack && !prio_queue) std::cout << "stack\n";
	else if(!queue && !stack && prio_queue) std::cout << "priority queue\n";
	else std::cout << "not sure\n";
    }
    return 0;
}
