# LIBFT

## 목적
이후 프로젝트에서 활용될수 있도록 자주 사용되는 함수들을 재구성하여 나만의 C library를 제작하는 것.(Version : 15)

## 내용
#### Part 1 - Libc functions
이미 존재하는 함수들을 man에 정의되어있는대로 구현하기.

#### Part 2 - Additional functions
C standard library에 포함되어있지 않지만 유용하게 사용될 함수를 주어진 프로토 타입에 맞춰 구현하기.

#### Bonus part
리스트를 사용할 때 유용하게 활용할 수 있는 함수들 구현하기.

## Part 1 - Libc functions

- `isalpha`, `isdigit`, `isalnum`, `isascii`, `isprint`
  - 들어온 매개변수가 알파벳(alpha), 숫자(digit), 알파벳 혹은 숫자(alnum), 아스키문자(ascii), 출력가능한 아스키 코드 값(print)인지 판별하여 참이라면 0이 아닌 값을 리턴하고, 거짓이라면 0을 리턴한다.
  - isprint 같은 경우 man을 사용해보면 해당하는 값을 8진법(octal)으로 보여주기 때문에 외우지 않았더라도 쉽게 구현할 수 있다.
- `toupper`, `tolower`
  - 알파벳 소문자를 대문자로, 대문자를 소문자로 바꿔준다.
- `strlen`, `strlcpy`, `strlcat`, `strnstr`, `strchr`, `strrchr`
  - strlen 함수는 문자열 s의 길이를 계산한다.
  - strlcpy 함수는 src문자열을 dst문자열에다가 dstsize 만큼 복사해주는것이다. dstsize는 ‘\0’을 포함한 크기이기때문에 ‘\0’값이 보장되어있다. 반환값은 src의 길이 이다.
  - strlcat 함수는 문자열 dst뒤에 src를 이어 붙이는 함수이다. 
    - 반환값은 일반적으로 dstlen +srclen 이 반환되지만 (dstsize < dstlen + 1)인 경우 dstsize +srclen 이 반환된다.
     - 의문점 man strlcat에서는 return을 두가지 케이스로 나누는것에 대한 내용을 찾을 수 없다. 하지만 테스트를 해보면 일반적으론 dstlen + srclen이 반환되지만 (dstsize < dstlen + 1) 인 경우에는 dstsize + srclen가 반환된다. man에 설명이 없어서 왜 이렇게 나눴을까 궁금해서 개인적으로 생각을 해봤다. 정상적인 경우라면 dstlen + srclen이 반환되는데 (dstsize < dstlen + 1) 인경우에는 원래 원하던 cat작동(dst뒤에 src 붙이기)이 제대로 이루어지지 않는다. 그러면 cat작동이 잘 이루어지지 않았다는것을 나타내기 위해 dstsize + srclen. 그러면 원래 원하던 반환값과 다른 값이 나오니까 제대로 작동이 되지 않았구나 라고 알 수 있다. 라고 생각을 했었는데 dstlen, srclen, dstsize가 모두 같은 크기라면 반환값이 동일하기때문에 알아차릴 수 없다. 또한 잘 이루어지지 않았을때 0을 반환하면 한눈에 알아차릴텐데 굳이 dstsize + srclen을 반환한 이유는 무엇일지 제대로 해결하지는 못하였다.
  - strnstr 함수는 haystack 문자열의 len길이 이내에 문자열 needle이 있는지 확인하여 있다면 needle의 첫번째 포인터를 반환한다. needle이 haystack어디에도 없다면 NULL을 리턴한다. needle is an empty string이면(empty string은 ""즉 '\0'인 상황을 의미한다 NULL이 아님) 바로 haystack 리턴한다 (man에 명시되어있다.)
  - strchr 함수는 문자열 s에서 문자 c를 탐색하는 함수이다. 문자열 s에서 문자 c가 처음 발견된 곳의 포인터를 반환한다. 해당하는 c가 없다면 NULL을 반환한다.
    - 의문점 strchr, strrchr을 구현한 다른 분들의 코드중 c를 unsigned char로 형변환하는 경우가 은근히 많았다. man을보면 char로 캐스팅하라고 명시되어있다. 굳이 언사인드차를 사용한 이유는 무엇일까? 이걸 최신 cppreference나 다른 원문봐도 int c는 converted to a char 라고 되어있다. unsigned char를 사용한 지인들에게 물어보니 char나 unsigned char나 오버플로우터졌을때를 생각해보면 char일경우에 -값이 들어가는데 이것보단 언사인드로 그냥 값띄우는게 나을것같아서 했다는 의견. 지인들에게 물어보니 이건 개인취향일수 있다고 답변을 들었다. 인터넷 검색을 통해 얻은 다른 답변중 하나는 검색할 문자 c는 int로 주어지기 때문에 unsigned char로 형변환하여 검색한다.-> char로 형변환하지 않는 이유는, 특정 아키텍쳐 cpu를 사용하는 환경에서는 unsigned char가 디폴트이다. 이러한 환경에서 char을 사용했을 때 unsigned char로 바뀌어 적용된다.이렇듯 char을 이용했을 때 환경마다 다르게 동작할 수 있기 때문에 관례상 unsigned char을 이용한다. ←라는 글을 보았다. 나는 man에 있는대로 구현하는것이 더 옳다고 생각되어 char를 사용하였다. unsigned char를 사용하였다면 man에 나와있는걸 무시하고 unsigned char를 사용한 자신만의 합당한 근거가 있어야 할것이다.(42의 채점기인 moulinette은 따로 잡지 않는다)
  - strrchr 함수는 문자열 s에서 문자 c를 뒤에서부터 탐색하는 함수이다. 문자열 s에서 문자 c가 처음 발견된 곳의 포인터를 반환한다. 해당하는 c가 없다면 NULL을 반환한다.
- `memset`, `bzero`, `memcpy`, `memmove` `memchr`, `memcmp`,
- `atoi`
- `calloc`, `strdup`

## Part 2 - Additional functions

- `substr`, `strjoin`, `strtrim`, `split`, `itoa`, `strmapi`, `striteri`
- `putchar_fd`, `putstr_fd`, `putendl_fd`, `putnbr_fd`

## Bonus part

- `lstnew`, `lstadd_front`, `lstsize`, `lstlast`, `lstadd_back`, `lstdelone`, `lstclear`, `lstiter`, `lstmap`

추가할 내용 메모리 구조, 댕글링포인터, size_t, 운영체제별 자료형 바이트변화, 널가드, 파일디스크립터
