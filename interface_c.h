
#define MYSQL_RESULT_SET    "global_result_set"
#define COMMAND_ARGS        "global_command_args"
#define REDIS_RESULT        "global_redis_result"
#define UUID_RESULT 		"global_uuid_result"
#define ERRNO 				"ERRNO"

//package 模块
void write_begin(short cmd);
void write_end();
void write_int(int value);
void write_short(short value);
void write_uint(unsigned long value);
void write_string(char* value);
void write_byte(unsigned char value);
void write_binary(char *buf, int len);

int  send_raw_packet(int fd);
int  send_packet(int fd);
int  send_buffer(int fd, char* buffer, int len);
int  transfer(int fd);
int  transfer_raw(int fd);

//log 模块m
void error(const char* msg);
void info(const char* msg);
void debug(const char* msg);

int create_timer();
int start_timer(unsigned long timer_id, int time);
int stop_timer(unsigned long timer_id);
int reset_timer(unsigned long timer_id);
int clear_timer(unsigned long timer_id);

// add by austinch 2012/06/13
// return remain second of timer 
int remain_timer(unsigned long timer_id);

int create_listener(int port);
int connect_server(char* ip, int port);
int connect_server(char* ip, int port, bool is_encrypt, int conn_flag);
int close_socket(int fd);

//mysql
int connect_mysql(const char* host, const char* user, const char* password, const char* dbname, unsigned int port);
int query(const char* mysql);

//redis
int connect_redis(const char* host, unsigned int port, unsigned short second = 0);
int get_redis_value(const char* key);
int set_redis_value(const char* key, const char* value);
int set_redis_expire(const char* key, int expire);

int Enqueue(const char* queue, const char* value);
int Dequeue(const char* queue);

bool IsActived();

int S_IsMember(const char* key, const char* value);
int S_IsMember(const char* key, const int value);

int HSet(const char* key, const int field, const char* value);
int HGet(const char* key, const int field);
int HDel(const char* key, const int field);

int Del(const char* key);



//uuid
void NewUUID();

//time wheel

int 
tw_run();

