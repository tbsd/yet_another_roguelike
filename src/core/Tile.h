//
// Created by tbsd on 11/20/20.
//

#ifndef TBSD_ROGUELIKE_TILE_H
#define TBSD_ROGUELIKE_TILE_H


namespace tbsd {
  class Tile {
  public:
    using TileType = char;
    TileType type;

    Tile() : type('.') {};
  };
}


#endif //TBSD_ROGUELIKE_TILE_H
