import { useState, useEffect, useRef } from 'react';

interface UseLQIPArgs {
  placeholder: string;
  full: string;
}

export function useLQIP({ placeholder, full }: UseLQIPArgs): [string, boolean] {
  const [loaded, setLoaded] = useState(false);
  const img = useRef<null | HTMLImageElement>(null);
  useEffect(() => {
    img.current = new Image();
    img.current.onload = () => {
      setTimeout(() => setLoaded(true), 1500);
      img.current = null;
    };
    img.current.src = full;
  }, []);
  return [loaded ? full : placeholder, loaded];
}
