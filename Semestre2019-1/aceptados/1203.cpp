//codigo propio
#include <iostream>
#include <queue>
using namespace std;

class Query{
public:
	int Q_num, period, next;
	bool operator <(const Query& query2) const{
		if(query2.next < next) return true;
		else if(query2.next > next) return false;
		return query2.Q_num < Q_num;
	}
};

int main(){
	int Q_num, period, k;
	char c;
	priority_queue<Query> cola;

	scanf("%c", &c);
	while(c!='#'){
		scanf("%*s %d %d\n", &Q_num, &period);
		Query q;
		q.Q_num = Q_num;
		q.period = period;
		q.next = period;
		cola.push(q);
		scanf("%c", &c);
	}

	scanf("%d", &k);
	
	while(k--){
		Query q = cola.top();
		cola.pop();
		printf("%d\n",q.Q_num);
		q.next += q.period;
		cola.push(q);
	}

	return 0;
}