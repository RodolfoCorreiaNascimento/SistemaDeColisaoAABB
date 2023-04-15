/*
* Detecção de colisão usando Axis-Aligned Bounding Boxes (AABB)
*/
#include <iostream>
#include "aabb_colisao.h"

int main()
{
    // Exemplo de uso da função de colisão AABB
    AABBColisao::Objeto obj1(0, 0, 16, 16);
    AABBColisao::Objeto obj2(17, 17, 16, 16);

    // Criar um objeto da classe AABBColisao para usar a função colisaoAABB
    AABBColisao aabbColisao;
    bool colisao = aabbColisao.colisaoAABB(obj1, obj2);

    if (colisao) 
    {
        /* code */
        std::cout << "Colisao detectada!" << std::endl;
    } else
    {
        /* code */
        std::cout << "Sem colisao." << std::endl;
    }
    
    return 0;
}