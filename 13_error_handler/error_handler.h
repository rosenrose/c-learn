#ifndef ERROR_HANDLER_H
#define ERROR_HANDLER_H

void register_err_handler(void (*handler)(const char *const msg));
void log_err(const char *const msg);
void default_err_handler(const char *const msg);

#endif /* ERROR_HANDLER_H */
