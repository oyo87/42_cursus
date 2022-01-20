# **LIBFT**

## **목적**

이후 프로젝트에서 활용될수 있도록 자주 사용되는 함수들을 재구성하여 나만의 C library를 제작하는 것.(21.12.20, Version : 15)

## **내용**

### **Part 1 - Libc functions**

이미 존재하는 함수들을 man에 정의되어있는대로 구현하기.

### **Part 2 - Additional functions**

C standard library에 포함되어있지 않지만 유용하게 사용될 함수를 주어진 프로토 타입에 맞춰 구현하기.

### **Bonus part**

리스트를 사용할 때 유용하게 활용할 수 있는 함수들 구현하기.  

## **Part 1 - Libc functions**

- `isalpha`, `isdigit`, `isalnum`, `isascii`, `isprint`
    
    ```c
    int isalpha(int c);
    int isdigit(int c);
    int isalnum(int c);
    int isascii(int c);
    int isprint(int c);
    ```
    
    - 들어온 매개변수가 알파벳(alpha), 숫자(digit), 알파벳 혹은 숫자(alnum), 아스키문자(ascii), 출력가능한 아스키 코드 값(print)인지 판별하여 참이라면 0이 아닌 값을 리턴하고, 거짓이라면 0을 리턴한다.
    - isprint 같은 경우 man을 사용해보면 해당하는 값을 8진법(octal)으로 보여주기 때문에 외우지 않았더라도 쉽게 구현할 수 있다.
- `toupper`, `tolower`
    
    ```c
    int toupper (int c);
    int tolower (int c);
    ```
    
    - 알파벳 소문자를 대문자로(toupper), 대문자를 소문자로(tolower) 바꿔준다.
- `strlen`, `strlcpy`, `strlcat`, `strnstr`, `strchr`, `strrchr`
    
    ### 1. strlen
    
    ```c
    size_t	ft_strlen(const char *s);
    ```
    
    - strlen 함수는 문자열 s의 길이를 계산한다.(널 종단 문자열은 포함 안함)
    
    ### 2. strlcpy
    
    ```c
    size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
    ```
    
    - strlcpy 함수는 src문자열을 dst문자열에다가 dstsize 만큼 복사해주는것이다. dstsize는 ‘\0’을 포함한 크기이기때문에 ‘\0’값이 보장되어있다. 반환값은 src의 길이 이다.
    
    ### 3. strlcat
    
    ```c
    size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
    ```
    
    - strlcat 함수는 문자열 dst뒤에 src를 이어 붙이는 함수이다.
        - 반환값은 일반적으로 dstlen +srclen 이 반환되지만 (dstsize < dstlen + 1)인 경우 dstsize +srclen 이 반환된다.
        - 의문점 man strlcat에서는 return을 두가지 케이스로 나누는것에 대한 내용을 찾을 수 없다. 하지만 테스트를 해보면 일반적으론 dstlen + srclen이 반환되지만 (dstsize < dstlen + 1) 인 경우에는 dstsize + srclen가 반환된다. 이렇게 나누어둔 이유는 무엇일까?<br>
        정상적인 경우라면 dstlen + srclen이 반환되는데 (dstsize < dstlen + 1) 인경우에는 원래 원하던 cat작동(dst뒤에 src 붙이기)이 제대로 이루어지지 않는다. 그러면 cat작동이 잘 이루어지지 않았다는것을 나타내기 위해 dstsize + srclen. 그러면 원래 원하던 반환값과 다른 값이 나오니까 제대로 작동이 되지 않았구나 라고 알 수 있다.<br>
        위의 내용으로 생각을 했었는데 dstlen, srclen, dstsize가 모두 같은 크기라면 반환값이 동일하기때문에 제대로 작동되었는지 여부를 반환값만으로 알아차릴 수 없다. 또한 잘 이루어지지 않았을때 0을 반환하면 한눈에 알아차릴텐데 굳이 dstsize + srclen을 반환한 이유는 무엇일지 의문이다.
    
    ### 4. strnstr
    
    ```c
    char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
    ```
    
    - strnstr 함수는 haystack 문자열의 len길이 이내에 문자열 needle이 있는지 확인하여 있다면 needle의 첫번째 포인터를 반환한다. needle이 haystack어디에도 없다면 NULL을 리턴한다. needle is an empty string이면(empty string은 ""즉 '\0'인 상황을 의미한다 NULL이 아님) 바로 haystack 리턴한다 (man에 명시되어있다.)
    
    ### 5. strchr
    
    ```c
    char	*ft_strchr(const char *s, int c);
    ```
    
    - strchr 함수는 문자열 s에서 문자 c를 탐색하는 함수이다. 문자열 s에서 문자 c가 처음 발견된 곳의 포인터를 반환한다. 해당하는 c가 없다면 NULL을 반환한다.
        - 의문점 strchr, strrchr을 구현한 다른 분들의 코드중 c를 unsigned char로 형변환하는 경우가 은근히 많았다. man을보면 char로 캐스팅하라고 명시되어있다. 굳이 언사인드차를 사용한 이유는 무엇일까? 최신 cppreference나 다른 원문봐도 int c는 converted to a char 라고 되어있다.<br>
        unsigned char를 사용한 지인들에게 물어보니 char나 unsigned char나 오버플로우가 발생했을때를 생각해보면 char일경우에 -값이 들어가는데 이것보단 unsigned로 처리하는게 나을것같아서 했다는 의견. 지인들에게 물어보니 이건 개인취향일수 있다고 답변을 들었다.<br>
        인터넷 검색을 통해 얻은 다른 답변중 하나는 검색할 문자 c는 int로 주어지기 때문에 unsigned char로 형변환하여 검색한다.-> char로 형변환하지 않는 이유는, 특정 아키텍쳐 cpu를 사용하는 환경에서는 unsigned char가 디폴트이다. 이러한 환경에서 char을 사용했을 때 unsigned char로 바뀌어 적용된다. 이렇듯 char을 이용했을 때 환경마다 다르게 동작할 수 있기 때문에 관례상 unsigned char을 이용한다.<br>
        위의 글을 보아도 나는 man에 있는대로 구현하는것이 더 옳다고 생각되어 char를 사용하였다. unsigned char를 사용하였다면 man에 명시되어있는  converted to a char를 무시하고 unsigned char를 사용한 본인만의 이유를 잘 설명할 수 있어야 할 것이다.(42의 채점기인 moulinette은 따로 잡지 않기 때문에 defense를 잘 수행하면 된다.)
    
    ### 6. strrchr
    
    ```c
    char	*ft_strrchr(const char	*s, int	c);
    ```
    
    - strrchr 함수는 문자열 s에서 문자 c를 뒤에서부터 탐색하는 함수이다. 문자열 s에서 문자 c가 처음 발견된 곳의 포인터를 반환한다. 해당하는 c가 없다면 NULL을 반환한다
- `memset`, `bzero`, `memcpy`, `memmove` `memchr`, `memcmp`
    
    ### 1. memset
    
    ```c
    void	*ft_memset(void *b, int c, size_t len);
    ```
    
    - len 바이트만큼 c의값으로 b를 채운다. c는 unsigned char로 convert한다고 man에 명시되어있다. b의 첫주소를 리턴한다.
    
    ### 2. bzero
    
    ```c
    void	ft_bzero(void *s, size_t n);
    ```
    
    - n바이트만큼 0의값을 s에 채운다 memset c값에 0을 넣은것과 같다. n이 0이라면 아무것도 하지 않는다. memset(s, 0,n) 으로 같은 결과를 만들 수 있다. bzero는 더이상 사용되지 않는다고 하니(deprecated) memset을 사용하는것을 권장한다고 한다.
    
    ### 3. memcpy
    
    ```c
    void	*ft_memcpy(void *dst, const void *src, size_t n);
    ```
    
    - 메모리 영역 src의 n bytes만큼을 dst로 복사한다. src와 dst의 메모리 영역이 겹쳐서는 안됨. 메모리 영역이 겹치면, memcpy 대신 memmove를 사용해야한다. original value of dst 를 리턴한다.
    - dst가 src보다 크면 overlap 가능성이 생긴다. 예를들어 memcpy(dst + 1, dst, n) 인 경우 dst가 123456 라고 예시를 들면 처음에 dst+1인 2자리에 src의 값인 1이들어가 113456이됨 dst+2인 3자리에 src+1의 방금복사된 1이들어가 111456이됨 이 작업이 반복되어 결국 111111이되어 원하는 cpy가 이루어지지 않는다. 이런 상황에서는 memmove가 적절하다.
    - man의 return 값에 the original value of dst. 라고 적혀있어서 처음 제작할 때  복사가 이루어지기 전의 값을 리턴해야 하나? 하는 착각을 했었는데 어차피 dst는 주소를 가리키는 포인터 이기 때문에 내부의 값은 연관이 없다.
        - memcpy와 strncpy의 차이  
        strncpy 는 정해진 갯수만큼 복사를 하되, ‘\0’ 을 만나면 멈춘다.  하지만 memcpy 는 ‘\0’에 상관없이 무조건 n바이트만큼을 복사한다.  
        예를 들어 char *A="ABCD\0EFG" 일때 memcpy(B,A,8) 하고 출력해보면 ‘\0’뒤의 EFG가 찍혀 나온다. strncpy(B,A,8) 은 그렇지 않고 ‘\0’만나면 복사 종료
    
    ### 4. memmove
    
    ```c
    void	*ft_memmove(void *dst, const void *src, size_t len);
    ```
    
    - 메모리 영역 src의 len bytes만큼을 dst로 복사한다. memcpy와 동일해 보이나 src와 dst의 메모리 영역이 겹칠 때 사용해도 복사가 제대로 이루어진다..  memcpy와 마찬가지로 original value of dst.를 리턴한다.
    - 구현을 할때 overlap이 발생할 가능성이 있는 src < dst 의 경우 뒤에서부터 복사하는 방식을 사용하여 문제없이 복사가 되도록 하였다.
    - memcpy, memmove 둘 다 복사의 기능을 가진 함수이다. memmove는 복사할 것을 버퍼에 복사 → 해당 위치에 가서 버퍼에 복사된 것을 붙여넣음. 따라서, 속도는 memcpy가 우위, 안정성은 memmove가 우위이다.
    
    ### 5. memchr
    
    ```c
    void	*ft_memchr(const void *s, int c, size_t n);
    ```
    
    - 문자열 s에서 처음 나타난 c(unsigned char로 convert)를 찾는 함수이다  
    리턴값은 첫c값을 찾아낸 포인터를 리턴하는데, 만약 n바이트내에 c값이 존재하지 않는다면 NULL을 리턴한다.
    - strchr과 달리 memchr에서는 unsigned char로 convert하라고 명시되어있어서 왜 char가 아닌 unsigned char로 하는지에 대한 이유를 42 slack에서 찾을 수 있었다.
        
        ---
        
        1. Memset, memcpy 등의 함수는 이름과 같이 메모리의 정보 그대로를 복사하는 함수입니다. 그 메모리가 나타내는 값(value)을 복사하는 게 아니라 메모리의 비트열을 그대로 복사하는 것이 목적인 굉장히 저수준(low-level)의 목적을 가진 함수이죠. C 명세서에서는 이런 오브젝트의 비트열을 object representation 이라고 합니다. C에서의 오브젝트란 할당된 공간에 유의미한 값이 들어있는 것입니다. 쉽게 보면 변수를 메모리적인 관점에서 본 것이라고 이해해도 될 것 같습니다. 이제 메모리의 데이터를 복사하는 것이란 이 object representation을 복사하는 것이라는 것을 알 수 있습니다. Object representation이 곧 메모리의 비트열이기 때문이죠. 그런데 c명세서에서 object representation을 정의할 때 이렇게 정의하고 있습니다. "모든 n바이트의 객체는 unsigned char[n] 형태의 메모리에 복사 가능헤야 하며 이 때 그 비트열을 object representation이라고 정의한다". 이렇듯 그 정의 자체가 unsigned char에 의존하기 때문에 메모리 관련 함수에는 unsigned char를 사용합니다.  
        2. C언어 명세서에서 바이트가 항상 8비트를 의미하지는 않습니다. C언어에서 바이트와 char는 서로 비교하기 좋으니 같이 이야기하겠습니다. 우선 명세 상 바이트는 "addressable unit 이며 시스템의 default character set을 저장할 수 있어야 한다" 라고 정의되며, 자료형의 char타입을 설명한 절에서 char는 "시스템의 default characrer set을 저장할 수 있어야 하며 그 동작은 signed char 혹은 unsigned char와 동일해야 한다. 다만 그 선택은 컴파일러 구현체의 자유이다" 라고 정의됩니다. 여기에서 바이트가 꼭 8비트여야 하는 것이 아니라 default character set을 저장할 수 있으며 addressable unit이기만 하면 된다는 것을 알 수 있습니다. 그리고 char는 거의 동일한 정의에서 addressable unit만 빠져있다는 것도 알 수 있죠. 이제 중간과정을 조금 생략해서, 명세서에 "바이트와 char는 동일하다" 라는 명시적 언급은 없지만 여러 조항들을 종합해보면 바이트와 char는 같은 사이즈임을 추론할 수 있습니다. 결국 char가 16비트인 시스템에서는 16비트가 1바이트가 되는 것이죠.  
        3. 다시 이어서 바이트와 char에 대한 이야기를 이어가자면, c언어 명세서에는 CHAR_BIT 라는 것을 정의하는데요, 이름대로 char 의 크기를 비트수로 나타낸 것입니다. Char가 8비크라면 CHAR_BIT는 8이 되고 CHAR가 16비트라면 CHAR_BIT는 16이 되는 식이지요. 그리고 C 명세 상 바이트가 CHAR_BIT와 동일하다는 명시적 언급은 없는 것으로 알고 있는데 여러 조항들을 조합하면 결국 바이트의 크기가 CHAR_BIT와 동일하다는 결론을 추론할 수 있다고 합니다. 그리고 CHAR_BIT 의 예시를 8비트로 서술하며 "모든 구현체에서 CHAR_BIT의 크기는 이보다 커야 한다" 라고 기술하고 있습니다. 이 부분이 우리가 흔히 알고 있는 "char 형은 크기가 8비트 이상이어야 한다" 라는 주장의 근거로 쓰이는 명세입니다.  
        4. 추가로 재밌는 것이 위의 char와 마찬가지로 모든 자료형이 보장해야 하는 최소범위에 대한 명세는 자료형을 설명하는 장에 없습니다. <limits.h> 를 정의하는 절에서 CHAR_MAX, INT_MIN 등을 정의하면서 숫자도 하나씩 같이 써 주고 "모든 컴파일러 구현체들은 이 수의 절대값보다 큰 수로 limits.h의 매크로들을 정의해야 한다" 라고 기술함으로써 각 자료형의 최소범위를 정의합니다.  
        5. C언어의 공식 명세서는 유료이며 저작권으로 보호받기에 인터넷에서 구할 수 없습니다. 하지만 공식 명세서로 출판되기 전의 수정 단계에 있는 draft 버전을 무료로 공개해 줍니다. 인터넷에서 보는 대부분의 c 명세서는 이 draft버전일 겁니다. 제가 쓴 글도 c99의 draft를 기반으로 하고 있습니다. C11에서는 변경된 내용이 있을 수도 있습니다. 그래도 최종 draft는 거의 확정되기 직전 단계이기 때문에 최종 표준안과 크게 다른 부분은 앖을 겁니다. 그래서 대부분의 스택오버플로우 답변, 위키피디아 등에서도 draft를 출처로 사용합니다.  
    
    ---
    
    - c명세서에서 object representation을 정의할 때 이렇게 정의하고 있습니다. "모든 n바이트의 객체는 unsigned char[n] 형태의 메모리에 복사 가능헤야 하며 이 때 그 비트열을 object representation이라고 정의한다". 이렇듯 그 정의 자체가 unsigned char에 의존하기 때문에 메모리 관련 함수에는 unsigned char를 사용합니다.  
    이렇게 정의가 되어있으므로 메모리관련에서는 언사인드 차를 사용한다. 정도로 이해하고 넘어갔다.
    
    ### 6. memcmp
    
    ```c
    int	ft_memcmp(const void *s1, const void *s2, size_t n);
    ```
    
    - 메모리영역 s1,s2를 바이트단위로 비교한다. n바이트 까지만 비교한다.리턴값 같으면 0 다르면 s1 - s2
    - man에서 unsigned char로 비교를 하라고 되어 있어 unsigned char *형태의 새로운 변수a1, a2에 담은 후에 unsigned char 형태의 a1 - a2 를 리턴하였다.(실제 코드에서는 인덱스를 활용하여 a1[i] - a2[i])
        - 의문점 왜 함수에서 처음부터 unsigned char * 형태의 s1, s2를 받지 않고 const void *s1, s2를 받았을까? 해결하지 못하였다.
- `atoi`
    
    ### 1. atoi
    
    ```c
    int	ft_atoi(const char *str);
    ```
    
    - char형을 int형으로 바꿔주어 출력한다 조금더 정확하게는 (int) strtol(str, (char **)NULL, 10) 을 하는 것이다.  
long strtol(const char *restrict str, char **restrict endptr, int base); ←이것이 strtol함수인데 str을 long형으로 바꿔주는 것이다 이 함수는 진법도 설정이 가능하다. strtol의 반환값을 (int)로 바꿔서 다시 반환하는것이 atoi이다.  
strtol은 str에 처음 isspace를 확인하여 지나가고, +, - 부호를 확인한다. 반복하여 확인하는것이 아닌 단 한번만 확인한다. 그후 str내부의 연속된 char형 숫자들을 int형 숫자로 바꿔주고 부호를 맞춰주며 반환한다.
man strtol을보면 LONG_MIN언더플로우  LONG_MAX오버플로처리에 대해 적혀있다. 오버,언더플로우가 발생하면 각각 -1, 0 으로 고정된 값을 출력한다. strtol 내부함수를 이렇게 구현해 두었기 때문이다.
    - 이 예외처리가 상당히 골치아팠다. 42 채점기인 moulinette은 이 예외처리를 신경쓰지 않지만 이걸 제대로 예외처리하려면 의외로 공부해야할 부분이 많았다. 비트별, 운영체제별 int, long, long long의 값들이 모두 달랐다는 것과, 이 오버플로우 언더플로우 처리를 어떻게 할것인가 이다. 우선 64비트 맥 환경에서는 long과 long long이 같기때문에 long을 넘어서는 값을 long long 으로 처리하려하면 안된다.  
    
    - 나는 간단하게 LONG_MAX, LONG_MIN을 상수로 두고 이걸 초과하면 -1, 0으로 리턴하게 예외처리를 해두었지만 좋은 방법은 아니었다. 내가 짠 코드에서 테스트 해보았을때 어느정도 예외처리가 잘 되는것 같이 보이나 특정 인자를 넣으면 -1, 0처리가 실패하도록 테스트를 할  수 있다. num에 담는 과정에서 이미 언더, 오버플로우가 발생하기 때문이다.  운이 좋아 적당한 숫자가 담긴다면 -1, 0 처리가 가능하지만 아닌 케이스도 있게 된다. 이러한 방식으로 처리한다면 대부분 비슷한 이유로 완벽한 처리가 되지 않는다.  
    다른 동료분은 이 예외처리를 배열을 만들고 숫자의 자릿수를 계산하여, 자릿수가 오버,언더플로우가 터지는 자릿수가 오버플로우,언더플로우가 발생시키는 자릿수인지, 딱 오버플로우 언더플로우가 발생하는 자릿수라면 마지막자리의 값이 오버플로우, 언더플로우를 발생시키는 숫자인지를 확인하여 오버플로우, 언더플로우 발생여부를 확인하고 오버,언더플로우 발생이 확인되었다면 -1, 0 을 리턴하는 방법으로 처리하였는데 이런식으로 배열로 자릿수를 이용하여 처리하면 오류없이 예외 처리가 가능한 것 같다.
    
    > 참고자료 CPU 및 운영체제별 자료형 크기
    > 
    > 
    > ![image](https://user-images.githubusercontent.com/90134585/148958951-8fdc62b5-af3a-4f34-be21-5fc450b36a3f.png)
    > 
    > 출처 : [C 언어 코딩 도장: 85.3 데이터 모델 (dojang.io)](https://dojang.io/mod/page/view.php?id=737)
    > 
    > 참고 : [UNIX, Linux 및 Windows의 표준 데이터 유형 - IBM Documentation](https://www.ibm.com/docs/ko/ibm-mq/9.0?topic=ssfksj-9-0-0-com-ibm-mq-ref-dev-doc-q104610--htm)

- `calloc`, `strdup`
    
    ### 1. calloc
    
    ```c
    void	*ft_calloc(size_t	count, size_t	size)
    ```
    
    - size크기의 변수를 count개 만큼 저장할 수 있는 메모리 공간을 할당.
    할당된 메모리 공간에 0이라는 값을 넣어준다.
    - 리턴값 함수는 할당된 메모리에 대한 포인터를 반환한다. 만약 오류인 경우 NULL 포인터를 반환한다.
    
    ### 2. strdup
    
    ```c
    char	*ft_strdup(const char *s1)
    ```
    
    - strdup 는 s1 문자열을 동적할당한 새로운 곳에 복사하고 마지막 널까지 복제한다. 리턴 값은 s1을 복제한 포인터 반환한다.

## **Part 2 - Additional functions**

- `substr`, `strjoin`, `strtrim`, `split`, `itoa`, `strmapi`, `striteri`
- `putchar_fd`, `putstr_fd`, `putendl_fd`, `putnbr_fd`

## **Bonus part**

- `lstnew`, `lstadd_front`, `lstsize`, `lstlast`, `lstadd_back`, `lstdelone`, `lstclear`, `lstiter`, `lstmap`

추가할 내용 메모리 구조, 댕글링포인터, size_t, 운영체제별 자료형 바이트변화, 널가드, 파일디스크립터 더 깔끔하게 정리하기
