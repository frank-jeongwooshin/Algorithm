# C++ 연산자 중복

## 클래스 타입(사용자 정의 타입)에도 연산자를 사용할 수 있도록 해주는 문법

ex)
int main(){
    int n1 = 10, n2 = 20;

    cout << n1 + n2 << endl; // 30
}
위의 코드는 기본적으로 컴파일러에 내장되어 있기 때문에 사용 가능

class Point{
    int x, y;

public:
    Point(int _x=0, int _y=0):x(_x), y(_y){}
    void Print(){
        cout << x << ', ' << y << endl;
    }

    **
    Point operator+(const Point &arg){
        Point pt;
        pt.x = this->x + arg.x;
        pt.y = this->y + arg.y;

        return pt;
    }
    **
}

int main(){
    Point p1(2, 3), p2(5, 5);

    p1 + p2; // p1.operator+(p2) 와 같음
    p1 * p2; // p1.operator*(p2) 와 같음
    p1 = p2; // p1.operator=(p2) 와 같음
    p1 == p2; // p1.operator==(p2) 와 같음
    p1 += p2; // p1.operator++(p2) 와 같음
}
위의 코드처럼 할 경우 에러가 남
-> Point 클래스에 멤버 함수 operator+()가 정의 되어 있어야함
-> ** 사이의 함수가 정의 되어 있다면 '+' 사용 가능(Python의 매직 함수와 비슷)

## 연산자 중복 불가능 연산자
 - .(멤버 접근 연산자)
 - .*(멤버 지시 포인터 연산자)
 - ::(범위 지정 연산자)
 - ?:(조건 연산자)
 - typeid, c++형변환 연산자


# STL표준 C++라이브러리
## Standard Template Library

### 주요 구성 요소
 - 컨테이너(Container): 객체들을 저장하는 객체 or 클래스(Vector, list, string, map 등)
 - 반복자(Iterator): 컨테이너에 저장된 요소를 순회하고 접근하는 객체 or 클래스(추상화)
 - 알고리즘(Algorithm): 데이터를 다루기 위한 일련의 함수(find, short, search 등)
 - 함수자(Functor): 함수처럼 동작하는 객체로 operator()연산자를 오버로딩한 클래스의 객체

### 컨테이너
 - 동일한 타입의 객체를 저장, 관리할 목적으로 만들어 놓은 클래스
 #### 표준 시퀀스 컨테이너(Standard Sequence Container)
 - vector, string, deque, list인 선형 방식의 컨테이너
 #### 표준 연관 컨테이너(Standard Associative Container)
 - Set, Multiset, map, multimap인 비선형 방식의 컨테이너

 ### 예시
 #include <iostream>
 #include <vector>

 using namespace std;
 int main(){
     vector<int> int_vector;

     int_vector.push_back(10); // 10을 vector 마지막에 삽입
     int_vector.push_back(20); // 20을 vector 마지막에 삽입
     int_vector.push_back(30); // 30을 vector 마지막에 삽입
 }


### 반복자
 - 포인터와 비슷한 역할. 단, 컨테이너에 저장된 객체들에 접근하고 순회하는 일반화된 방법을 제공
 - 특징: 내부 객체를 가리키고 접근할 수 있어야 함 / 내부 객체를 순회할 수 있어야 함

 #### 입력 반복자(input iterator): 현 위치의 데이터를 읽기만 가능한 반복자
 #### 출력 반복자(output iterator): 현 위치에 데이터를 쓰기만 가능한 반복자
 #### 순방향 반복자(forward iterator): 입•출력 반복자 기능 + 순방향으로 이동 가능한 반복자
 #### 양방향 반복자(Bidirectional iterator): 순방향 반복자 기능 + 역방향으로 이동 가능한 반복자
 #### 임의 접근 반복자(Random Access Iterator): 양방향 반복자 기능 + 반복자의 산술 연산이 가능한 반복자

 ### 예시
 #include <iostream>
 #include <vector>

 using namespcae std;
 int main(){
     vector<int> int_vector;

     int_vector.push_back(10); // 10을 vector 마지막에 삽입
     int_vector.push_back(20); // 20을 vector 마지막에 삽입
     int_vector.push_back(30); // 30을 vector 마지막에 삽입

     vector<int>::iterator iter; // iterator 기능
     for(iter = int_vector.begin(); iter != int_vector.end(); iter++){
         cout << *iter << endl; //*iter로 접근 가능 10 20 30
     }
 }


### 알고리즘
 - 여러 가지 문제들의 해결방법을 일반화된 함수로 제공

### 예시 - 정렬
#include <iostream>
#include <vector>
#include <algorithm> // 알고리즘을 불러옴
using namespace std;

int main(){
    vector<int> int_vector;

    int_vector.push_back(10); // 10을 vector 마지막에 삽입
    int_vector.push_back(20); // 20을 vector 마지막에 삽입
    int_vector.push_back(30); // 30을 vector 마지막에 삽입
    int_vector.push_back(80);
    int_vector.push_back(5);

    vector<int>::iterator iter; // iterator 기능
    for(iter = int_vector.begin(); iter != int_vector.end(); iter++){
        cout << *iter << endl; //*iter로 접근 가능 10 20 30
    }

    sort(int_vector.begin(), int_vector.end()); // 시작과 마지막을 인자로 받아 정렬
}

### 예시 - for -> for_each()
#include <iostream>
#include <vector>
#include <algorithm> // 알고리즘을 불러옴
using namespace std;

void Print(const int &n){
    cout << n << ' ';
}

int main(){
    vector<int> int_vector;

    int_vector.push_back(10); // 10을 vector 마지막에 삽입
    int_vector.push_back(20); // 20을 vector 마지막에 삽입
    int_vector.push_back(30); // 30을 vector 마지막에 삽입
    int_vector.push_back(80);
    int_vector.push_back(5);

    for_each(int_vector.begin(), int_vector.end(), Print); // 10~5출력


### 함수자
 - 함수처럼 사용할 수 있는 객체

### 예시 - less<> greater<>
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

void Print(const int &n){
    cout << n << ' ';
}

int main(){
    vector<int> int_vector;

    int_vector.push_back(10); // 10을 vector 마지막에 삽입
    int_vector.push_back(20); // 20을 vector 마지막에 삽입
    int_vector.push_back(30); // 30을 vector 마지막에 삽입
    int_vector.push_back(80);
    int_vector.push_back(5);

    for_each(int_vector.begin(), int_vector.end(), Print); // 10~5출력

    sort(int_vector.begin(), int_vector.end(), less<int>());
    // 내림차수
    sort(int_vector.begin(), int_vector.end(), greater<int>());
    // 오름차수
}

### less / greater 정의
template<class _Ty>
struct greater{
    bool operator()(const _Ty& _Left, const _Ty& _Right) const{
        return (_Left > _Right);
    }
}

template<class _Ty>
struct less{
    bool operator()(const _Ty& _Left, const _Ty& _Right) const{
        return (_Left < _Right);
    }
}


# Vector
- '시퀀스 컨테이너' 이면서 '연속 메모리 기반 컨테이너'
- insert(idx, value)
- erase(idx)

# List
- '시퀀스 컨테이너' 이면서 '노드 기반 컨테이너'
- 삽입, 삭제가 자주 발생할 때 사용하면 좋은 컨테이너
- push_front()도 사용 가능(양방향 반복자 제공)
- reverse_iterator로 반대로 iter함(rbegin(), rend())
- 삽입과 삭제가 '선형 시간'
- insert(idx, value)
- erase(idx)

# String
- basic_string<char>의 typedef
- '시퀀스 컨테이너' 이면서 '연속 메모리 기반 컨테이너'
- vector처럼 임의 접근 반복자 제공(iter += 2 등)
- '=', '==', '+=', 'substr', 'find' 등 사용 가능

# Deque
- '시퀀스 컨테이너' 이면서 '연속 메모리 기반 컨테이너'
- 앞, 뒤에 데이터 요소들이 추가, 삭제 될 수 있은 형태의 컨테이너
- push_front(), push_back(), pop_front(), pop_back(), insert() 등 제공

# Pair
- 한 쌍을 표현하기 위한 클래스
- pair<type, type>으로 표기 가능( 다른 type도 저장 가능)

### 예제
#include <iostream>
#include <string>

using namespace std;

int main(){
    pair<int, int> p1(10, 20);
    pair<int, string> p2(30, 'hi');
    pair<string, string> p3('bye', 'end');
}

# Set, Multiset
- '연관 컨테이너' & '노드 기반 컨테이너'
- 이진 트리 구현
- set: 유니크한 데이터셋의 균현 이진 트리
- multiset: 같은 데이터값을 가질 수 있는 set
- push함수가 없고 insert(value)함수가 있음
- equal_rage() - 데이터의 구간 반복자를 pair로 반환
- multiset의 경우 같은 값일 경우, equal_range시 first는 처음 만나는 idx이고, second의 경우 같은 값의 다음 값의 idx

### 예제
#include <iostream>
#include <set>
using namespace std;

int main(){
    set<int, less<int>> s; //greater도 사용 가능

    s.insert(50);
    s.insert(30);
    s.insert(60);
    s.insert(80);

    set<int, less<int>>::iterator iter;

    pair<set<int>::iterator, set<int>::iterator> iter_pair;
    iter_pair = s.equal_ragne(50); //iter_pair의 first가 50이 들어있는 idx
    // lower_bound는 first, upper_boun는 second
}

# Map, Multimap
- '연관 컨테이너' & '노드 기반 컨테이너'
- key와 value의 쌍으로 구성된 데이터 셋의 집합(key는 unique)
- map<key type, value type> name;
- key가 없다면 '추가', 있다면 '갱신'
- first는 key, second는 value

### 예제
#include <iostream>
#include <map>
using namespace std;

int main(){
    map<int, int> m;

    m[4] = 100;
    m[3] = 50;
    
    m.insert(pair<int, int>(5, 90));

    pair<int, int> pr(9, 10);
    m.insert(pr);
}


# STL 알고리즘
## for_each
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void Print(int n){
    cout << n << endl;
}

int main(){
    vector<ins> v;

    for(int i = 0; i <= 10; i++){
        v.push_back(i);
    }

    for(int i = 0; i <= 10; i++){
        cout << v[i] << endl;
    }

    //for_each
    for_each(v.begin(), v.end(), Print);
}

## find, count
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    vector<int> v;
    for(int i = 0; i < 10; i++){
        v.push_back(i);
    }

    vector<int>::iterator iter;
    iter = find(v.begin(), v.end(), 5);
    // 5가 v에 있다면 idx반환

    int total = count(v.begin(), v.end(), 3);
    // 3의 갯수 반환
}

## binary_search
- 정렬이 되어있다면 이진 탐색 실행
- binary_search(start_idx, end_idx, target)