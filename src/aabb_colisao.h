/*!
 * \file aabb_colisao.h
 * \brief Implementação da detecção de colisão usando Axis-Aligned Bounding Boxes (AABB) em C++
 * \author Rodolfo Correia do Nascimento
 * \link https://github.com/RodolfoCorreiaNascimento
 * \version 0.01
 * \date 14/04/2023
 * Descrição detalhada:
 * Este software é uma implementação de detecção de colisão usando Axis-Aligned Bounding Boxes (AABB) em C++.
 * A detecção de colisão é uma técnica usada em jogos e simulações para verificar se dois objetos estão se sobrepondo
 * no espaço, indicando uma colisão entre eles. O método AABB é uma abordagem simples e eficiente em que caixas
 * retangulares alinhadas aos eixos são usadas para representar os objetos, e a colisão é verificada
 * comparando as coordenadas dos lados dessas caixas.
 * A implementação é organizada em uma classe chamada AABBColisao, que contém uma estrutura chamada Objeto
 * para representar os objetos em colisão. A classe AABBColisao possui uma função pública chamada colisaoAABB,
 * que recebe dois objetos do tipo Objeto como parâmetros e verifica se há colisão entre eles com base em suas
 * coordenadas de posição, largura e altura. A função retorna true se houver colisão e false caso contrário.
 * Este software pode ser utilizado como uma ferramenta para adicionar detecção de colisão em jogos,
 * simulações ou outras aplicações que necessitem verificar interações entre objetos em um espaço 2D ou 3D.
 * Ele é adequado para projetos que buscam uma solução simples e eficiente para a detecção de colisão usando a
 * técnica AABB em C++.
 */

#ifndef _AABB_COLISAO_H_
#define _AABB_COLISAO_H_

/*! \class AABBColisao
    \brief Classe responsavel por todos os métodos e funções para operar
    a colisão entre dois objetos usando o algoritimo de colisão AABB.
*/
class AABBColisao
{
public:
    // Definição da estrutura Objeto
    /*!
 * \brief Estrutura para representar um objeto com colisão AABB.
 * \details Essa estrutura representa um objeto com colisão Axis-Aligned Bounding Box (AABB),
 *          que possui coordenadas x e y, largura e altura.
 */
struct Objeto
{
    int x;        /*!< Coordenada x do objeto. */
    int y;        /*!< Coordenada y do objeto. */
    int largura;  /*!< Largura do objeto. */
    int altura;   /*!< Altura do objeto. */

    /*!
     * \brief Construtor vazio que não aceita parâmetros.
     * \details Esse construtor cria um objeto vazio, onde não é obrigatório passar
     *          parâmetros ao criar o objeto.
     */
    Objeto()
    {
        // Construtor vazio, onde não é obrigatório passar parâmetros ao criar o objeto
    }

    /*!
     * \brief Construtor que aceita parâmetros.
     * \param _x Coordenada x do objeto.
     * \param _y Coordenada y do objeto.
     * \param _largura Largura do objeto.
     * \param _altura Altura do objeto.
     * \details Esse construtor cria um objeto com os parâmetros obrigatórios de x, y,
     *          largura e altura.
     */
    Objeto(int _x, int _y, int _largura, int _altura)
    {
        x = _x;
        y = _y;
        largura = _largura;
        altura = _altura;
    }
};


    /*!
     * \brief Função para verificar colisão entre AABB.
     * \param objeto1 Objeto 1 para verificação de colisão.
     * \param objeto2 Objeto 2 para verificação de colisão.
     * \return Retorna verdadeiro se houver colisão, falso caso contrário.
     */
    // Função para verificar colisão entre AABB
    bool colisaoAABB(const Objeto &objeto1, const Objeto &objeto2)
    {
        int esquerda1 = objeto1.x;
        int direita1 = objeto1.x + objeto1.largura;
        int cima1 = objeto1.y;
        int baixo1 = objeto1.y + objeto1.altura;

        int esquerda2 = objeto2.x;
        int direita2 = objeto2.x + objeto2.largura;
        int cima2 = objeto2.y;
        int baixo2 = objeto2.y + objeto2.altura;

        // Verifica a colisão nas coordenadas dos lados
        if (direita1 < esquerda2 || esquerda1 > direita2 || baixo1 < cima2 || cima1 > baixo2)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
};

#endif // _AABB_COLISAO_H_