import React, {Component} from 'react'
import Grid from '@material-ui/core/Grid'
import { Shortcuts } from 'react-shortcuts'
import Tile from './Tile.jsx'
import TileType from './TileType.js'
import Keymap from './Keymap.js'

class GameField extends React.Component {
  constructor(props) {
    super(props);
    this.sendAction = props.sendAction.bind(this)
    this.xSize = 50
    this.ySize = 50
    // TODO: remove field
    var tmpTiles = []
    for (var i = 0; i < this.ySize; ++i) {
      var tilesRow = []
      for (var j = 0; j < this.xSize; ++j) {
        tilesRow.push(React.createRef())
      }
      tmpTiles.push(tilesRow)
    }
    this.state = {tiles: tmpTiles}
    /// Coordinates of the most left top tile
    this.position = {x: 0, y: 0, z:0};
  }

  handleShortcuts = (action, event) => {
    switch (action) {
      case 'MOVE_LEFT':
        this.sendAction({move: {x: -1, y: 0, z: 0}});
        break
      case 'MOVE_RIGHT':
        this.sendAction({move: {x: 1, y: 0, z: 0}});
        break
      case 'MOVE_FORWARDS':
        this.sendAction({move: {x: 0, y: 1, z: 0}});
        break
      case 'MOVE_BACKWARDS':
        this.sendAction({move: {x: 0, y: -1, z: 0}});
        break
    }
  }


  changeTiles(props) {
    props.data.forEach((tile) => {
      // TODO: add guard against out of bounds
      if (tile.size !== 0) {
        this.state.tiles[tile.x][tile.y].current.changeTile({type: tile.type})
      }
    });
  }

  render() {
    var fieldJsx = [];
    for (var i = 0; i < this.ySize; ++i) {
      var row = []
      for (var j = 0; j < this.xSize; ++j) {
        row.push(<Tile ref={this.state.tiles[i][j]}/>);
      }
      fieldJsx.push(
        <Grid item>
        {row}
        </Grid>
      );
    }
    return (
      <Shortcuts name='GameField' handler={this.handleShortcuts}>
        <Grid container>
          {fieldJsx}
      {this.state.count}
        </Grid>
      </Shortcuts>
    );
  }
}

export default GameField;

