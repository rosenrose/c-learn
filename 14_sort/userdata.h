#ifndef USERDATA_H
#define USERDATA_H

typedef enum
{
    GENDER_MALE,
    GENDER_FEMALE,
    GENDER_NONE
} gender_t;

typedef struct
{
    unsigned short id;
    unsigned char age;
    gender_t gender;
} userdata_t;

typedef struct
{
    unsigned int sort_key;
    userdata_t user;
} radix_userdata_t;

#endif /* USERDATA_H */
