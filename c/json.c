#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cjson/cJSON.h>

#define BUFFER_SIZE 100

char *readJson(FILE *);
void allocationSuccessful(void *);

int main(void)
{
    FILE *input = fopen("sunrise.json", "r");
    char *unformatted = readJson(input);
    cJSON *json = cJSON_Parse(unformatted);
    cJSON *status = NULL;
    cJSON *results = NULL;
    cJSON *sunrise = NULL;
    cJSON *sunset = NULL;

    fclose(input);

    if (json == NULL)
    {
        const char *error = cJSON_GetErrorPtr();
        
        if (error != NULL)
        {
            fprintf(stderr, "Error before %s\n", error);
        }
        
        exit(EXIT_FAILURE);
    }
    
    results = cJSON_GetObjectItemCaseSensitive(json, "results");
    status = cJSON_GetObjectItemCaseSensitive(json, "status");
    
    if (!cJSON_IsString(status) || (strcmp(status->valuestring, "OK")))
    {
        fprintf(stderr, "Bad results: %s\n", status->valuestring);
        exit(EXIT_FAILURE);
    }
    
    sunrise = cJSON_GetObjectItemCaseSensitive(results, "sunrise");
    sunset = cJSON_GetObjectItemCaseSensitive(results, "sunset");

    printf("%s\n", unformatted);
    printf("Sunrise: %s  -  Sunset: %s\n", sunrise->valuestring, sunset->valuestring);

    cJSON_Delete(json);
    free(unformatted);

    return 0;
}

char *readJson(FILE *fp)
{
    int c, size = BUFFER_SIZE;
    size_t x = 0;
    char *buffer = malloc(BUFFER_SIZE * sizeof(char));

    allocationSuccessful(buffer);

    while ((c = fgetc(fp)) != EOF)
    {
        buffer[x++] = (char)c;

        if (x > size - 1)
        {
            size += BUFFER_SIZE;
            buffer = realloc(buffer, size * sizeof(char));

            allocationSuccessful(buffer);
            
            #ifdef DEBUG
            
            printf("New buffer size: %d\n", size);
            
            #endif
        }
    }

    // NULL terminate
    buffer[x] = '\0';
    
    #ifdef DEBUG
    
    printf("Buffer lengh: %zu\n", strlen(buffer));
    
    #endif

    return buffer;
}

void allocationSuccessful(void *buffer)
{
    if (buffer == NULL)
    {
        fprintf(stderr, "Error allocating memory.");
        exit(EXIT_FAILURE);
    }
}
