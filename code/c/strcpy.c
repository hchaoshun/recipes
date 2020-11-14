char *strcpy(char *des, char *src) {
    if (des == NULL || src == NULL)
        return NULL;
    if (des == src) return des;
    char *ptr = des;
    while ((*des++ = *src++) != '\0');
    return ptr;
}

char *strncpy(char *des, char *src, size_t n) {
    if (des == NULL || src == NULL)
        return NULL;
    if (des == src) return des;
    char *ptr = des;
    while ((n-- > 0) && (*des++ = *src++) != '\0');
    return ptr;
}

char *strcat(char *des, char *src) {
    if (des == NULL || src == NULL) return NULL;
    if (des == src) return des;
    char *ptr = des;
    while (*des != '\0') des++;
    while ((*des++ = *src++) != '\0');
    return ptr;
}
