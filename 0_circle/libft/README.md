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
  - strlcpy 함수는 src문자열을 dst문자열에다가 dstsize 만큼 복사해주는것이다. dstsize는 ‘\0’을 포함한 크기이기때문에 ‘\0’값이 보장되어있다. 리턴값은 소스의 길이를 리턴한다.
  - strlcat 함수는 문자열 src를 dst뒤에 이어 붙이는 함수이다. 
    - 자세히 나와있지 않은 man, 리턴
- `memset`, `bzero`, `memcpy`, `memmove` `memchr`, `memcmp`,
- `atoi`
  - 
- `calloc`, `strdup`

## Part 2 - Additional functions

- `substr`, `strjoin`, `strtrim`, `split`, `itoa`, `strmapi`, `striteri`
- `putchar_fd`, `putstr_fd`, `putendl_fd`, `putnbr_fd`

## Bonus part

- `lstnew`, `lstadd_front`, `lstsize`, `lstlast`, `lstadd_back`, `lstdelone`, `lstclear`, `lstiter`, `lstmap`

추가할 내용 메모리 구조, 댕글링포인터, size_t, 운영체제별 자료형 바이트변화, 널가드, 파일디스크립터
