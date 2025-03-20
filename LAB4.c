#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int dividePlayers(int* skill, int skillSize) {
    qsort(skill, skillSize, sizeof(int), compare);
    
    int totalSkill = skill[0] + skill[skillSize - 1];
    int chemistrySum = 0;
    
    for (int i = 0; i < skillSize / 2; i++) {
        if (skill[i] + skill[skillSize - 1 - i] != totalSkill) {
            return -1;
        }
        chemistrySum += skill[i] * skill[skillSize - 1 - i];
    }
    
    return chemistrySum;
}

int main() {
    int skill[] = {3, 2, 5, 1, 3, 4};
    int n = sizeof(skill) / sizeof(skill[0]);
    int result = dividePlayers(skill, n);
    printf("%d\n", result);
    return 0;
}
