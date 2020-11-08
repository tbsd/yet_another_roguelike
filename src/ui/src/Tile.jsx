import React from 'react';
import { makeStyles } from '@material-ui/core/styles';
import Grid from '@material-ui/core/Grid';
import './Tile.css';
import TileType from './TileType.js'

class Tile extends React.Component {
  constructor(props) {
    super(props);
    // this.tileType = props.tileType;
    this.state = {tileType: props.tileType}
  }

  getContent() {
    switch (this.state.tileType) {
      case TileType.HUMAN:
        return <div>@</div>;
        break;
      default:
      case TileType.GROUND:
        return <div>.</div>;
        break;
    }
  }

  changeTile(data) {
    this.setState({tileType: data.type})
  }

  render() {
    return (
      <Grid item className='Tile'>
        {this.getContent()}
      </Grid>
    );
  }
}

export default Tile;
